/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:17:25 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/13 17:17:26 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack		*sort(t_stack *a, t_stack *b, int count_a, t_bonus *fl)
{
	if (if_sorted(&a, &b))
		return (a);
	if (count_a == 2)
		sort_two(&a, &b, fl);
	else if (count_a == 3)
		sort_three(&a, &b, fl);
	else if (count_a >= 4 && count_a < 70)
		insert_sort(&a, &b, fl);
	else
		sorting(&a, &b, fl, count_a);
	return (a);
}

void		fresh(t_stack *a, t_stack *b, int *stack_a)
{
	free_stack(&a);
	free_stack(&b);
	free(stack_a);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bonus	fl;
	int		size;
	int		*stack_a;

	stack_a = NULL;
	b = NULL;
	if (valid_arg(argc, argv) == 0)
		return (write_error());
	if (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "--help")
	|| !ft_strcmp(argv[2], "--clear"))
		argv = parse_flags(argv, &fl);
	size = parse_stack(argv, &stack_a, 'p');
	if (argc >= 2)
		a = create_stack(&a, size, stack_a);
	if (size > 0)
		a = sort(a, b, size, &fl);
	else if (size < 0)
		write_error();
	fresh(a, b, stack_a);
	return (0);
}
