
#include "push_swap.h"

void print_bonus(t_stack *a, t_stack *b,t_bonus *fl)
{
    ft_printf("Command - %s\n", (fl)->command);
    ft_printf("Stack A: [ ");
    if (a)
    {
        while (a->next)
        {
            ft_printf("%d | ", a->nb);
            a = a->next;
        }
        ft_printf("%d ", a->nb);
    }
    ft_printf("]\n\n%s", "Stack B: [ ");
    if (b != NULL)
    {
        while (b->next != NULL)
        {
            ft_printf("%d | ", b->nb);
            b = b->next;
        }
        ft_printf("%d ", b->nb);
    }
    ft_printf("]\n\n");
}


t_stack *sort(t_stack *a, t_stack *b, int count_a, t_bonus *fl)
{
    if (if_sorted(&a, &b))
        return(a);
    if (count_a == 2)
        sort_two(&a, &b,fl);
    else if (count_a == 3)
        sort_three(&a,&b,fl);
    else if (count_a >= 4 && count_a < 70)
        insert_sort(&a,&b,fl);
    else
        sorting(&a,&b,fl,count_a);
    return (a);
}

t_bonus *parse_flags(int argc, char **argv, t_bonus *fl)
{
    fl = (t_bonus *)malloc(sizeof(t_bonus));
    (fl)->command = "";
    (fl)->flag_v = 0;
    (fl)->count_flag = 0;
    if (argv[1] && !ft_strcmp(argv[1],"--help"))
    {
        (fl)->count_flag++;
        ft_printf("./push_swap (unsorted stack)\tSort stack\n\n"
               "-v\t\tPrint stacks after command\n"
               "--clear\t\tClear window before sorting stacks\n");
        free(fl);
        exit(1);
    }
    if (argv[1] && (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1],"--clear")))
    {
        if (!argv[2])
        {
            ft_putstr("\033[31mError\033[0m\n");
            free(fl);
            exit(1);
        }
        (fl)->count_flag++;
        (fl)->flag_cl = 1;
        (fl)->flag_v = 1;
    }
    if (argv[2] && (!ft_strcmp(argv[2],"--clear") || !ft_strcmp(argv[2], "-v")))
    {
        fl->count_flag++;
        system("clear");
    }
    return (fl);
}


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *head = NULL;
    t_bonus *fl;
    int count_a;

    fl = parse_flags(argc,argv,fl);
    if (argc >= 2)
        a = create_stack(&head,argv,argc,fl);
    else
        return (ft_printf("How about sorting a stack?\n"
                       "Info ./push_swap --help\n"));
    count_a = lst_count(&a);
    if(fl->flag_v && if_sorted(&a,&b))
    {
        print_bonus(a,b,fl);
        return (0);
    }
	a = sort(a, b, count_a, fl);
	free(fl);
	free_stack(&a);
	free_stack(&b);
    return (0);
}
