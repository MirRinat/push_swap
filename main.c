#include <stdio.h>
#include "push_swap.h"

void print_bonus(t_stack *a, t_stack *b,t_bonus *fl)
{
   printf("Command - %s\n", (fl)->command);
    ft_putstr("Stack A: [ ");
    if (a)
    {
        while (a->next)
        {
            printf("%d | ", a->nb);
            a = a->next;
        }
        printf("%d ", a->nb);
    }
    printf("]\n\n%s", "Stack B: [ ");
    if (b != NULL)
    {
        while (b->next != NULL)
        {
            printf("%d | ", b->nb);
            b = b->next;
        }
        printf("%d ", b->nb);
    }
    printf("]\n\n");
}


t_stack *sort(t_stack *a, t_stack *b, int count_a, t_bonus *fl)
{
    if (if_sorted(&a, &b))
        return(a);
    if (count_a == 2)
        sort_two(&a, &b,fl);
    else if (count_a == 3)
        sort_three(&a,&b,fl);
    else if (count_a >= 4 && count_a < 7)
        sort_five(&a,&b,fl);
    else if (count_a >= 7 && count_a < 50)
        insert_sort(&a,&b,fl);
    else
        sorting(&a,&b,fl,count_a);
    return (a);
}

t_bonus *parse_flags(int argc, char **argv, t_bonus *fl)
{
    fl = (t_bonus *)malloc(sizeof(t_bonus));
    (fl)->command = "";
    (fl)->flag_cl = 0;
    (fl)->flag_help = 0;
    (fl)->flag_v = 0;
    (fl)->count_flag = 0;
    if (argv[1] && !ft_strcmp(argv[1],"--help"))
    {
        (fl)->count_flag++;
        printf("1. Print stacks after command :./push_swap -v from..to\n"
               "2. Clear window before sorting stacks: ./push_swap --clean from..to\n");
        exit(1);
    }
    if (argv[1] && (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1],"--clean")))
    {
        (fl)->count_flag++;
        (fl)->flag_v = 1;
    }
    if (argv[2] && (!ft_strcmp(argv[2],"--clean") || !ft_strcmp(argv[2], "-v")))
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
        return (printf("How about sorting a stack?\n"
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
