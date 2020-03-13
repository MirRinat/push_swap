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

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (!ft_strcmp(argv[1],"-v") && !ft_strcmp(argv[2],"--clear"))
	{
		parse_flags(argv, &fl);
		argv += 2;
	}
    size = parse_stack(argv, &stack_a,'p');
    a = create_stack(&a, size, &fl, stack_a);
    count_a = lst_count(&a);
    if (fl.flag_v && if_sorted(&a, &b))
    {
        print_bonus(a, b, &fl);
        return (0);
    }
    if (count_a > 0)
        a = sort(a, b, count_a, &fl);
    free_stack(&a);
    free_stack(&b);
    free(stack_a);
    return (0);
}