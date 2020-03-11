#include "./includes/push_swap.h"

void    print_mas(int *stack)
{
    int i = 0;
    while(stack[i])
        printf("%d",stack[i++]);
}

void print_list(t_stack *n)
{
    while (n)
    {
        ft_putnbr(n->nb);
        write(1," ",1);
        n = n->next;
    }
    ft_putchar('\n');
}

int			main(int argc, char **argv)
{
    t_stack	*a;
    t_stack	*b;
    t_bonus	fl;
    int size;
    int *stack_a;
    int		count_a;

//    a = NULL;
//	b = NULL;
	argc = 5;
    parse_flags(argv, &fl);
    size = parse_stack(argv, &stack_a,'p');
//    if (argc >= 2)
//    print_mas(stack_a);
    a = create_stack(&a, argc, &fl, stack_a);
//    else
//        return (ft_printf("Error\n"));
//    print_list(a);
    count_a = lst_count(&a);
    if (fl.flag_v && if_sorted(&a, &b))
    {
        print_bonus(a, b, &fl);
        return (0);
    }
    if (size > 0)
        a = sort(a, b, count_a, &fl);
    free_stack(&a);
    free_stack(&b);
    return (0);
}