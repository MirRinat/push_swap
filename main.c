#include <stdio.h>
#include "push_swap.h"

void print_bonus(t_stack *a, t_stack *b,t_bonus *fl)
{
//    ft_printf("Command - %s\n", (fl)->command);
    ft_putstr("Stack A: [ ");
    if (a)
    {
        while (a->next)
        {
            ft_printf("%d || ", a->nb);
            a = a->next;
        }
        ft_printf("%d ", a->nb);
    }
    ft_printf("]\n\n%s", "STACK B: [ ");
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



void			ft_chrfill(char **str, char c, int count)
{
    int			i;

    i = 0;
    while (i < count)
        (*str)[i++] = c;
    (*str)[count] = '\0';
}

t_stack *sort(t_stack *a, t_stack *b, int count_a, t_bonus *fl)
{
    if (if_sorted(&a, &b))
        return(NULL);
    if (count_a == 2)
        sort_two(&a, &b,fl);
    else if (count_a == 3)
        sort_three(&a);
    else if (count_a >= 4 && count_a < 7)
        sort_five(&a,&b);
    else if (count_a >= 7 && count_a < 50)
        insert_sort(&a,&b);
    else
        sorting(&a,&b,count_a);
    return (a);
}

//
//int parse_flags(char **argv)


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *head = NULL;
    char *ptr;
    t_bonus fl;
    int count_a;


    (*fl).flag_cl = 0;
    fl->flag_help = 0;
    fl->flag_v = 0;
    fl->count_flag = 0;

    if (argc == 1)
        return (ft_printf("Error\n"));
    if (!ft_strcmp(argv[1], "-v"))
    {
        (fl)->count_flag++;
        (fl)->flag_v = 1;
    }
    if (!ft_strcmp(argv[1],"--clean"))
    {
        fl->count_flag++;
        system("clear");
    }
    if (argc >= 2)
        a = create_stack(&head,argv,argc,fl);
//    print_bonus(a,b);
    count_a = lst_count(&a);
	a = sort(a, b, count_a, fl);
//	print_list(a);
//    print_bonus(a,b);
	free_stack(&a);
	free_stack(&b);
    return (0);
}
