/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:57:04 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:58:02 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		fresh_c(t_stack *a, t_stack *b, int *stack_a)
{
	free_stack(&a);
	free_stack(&b);
	free(stack_a);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bonus fl;
	int		*stack_a;
	int		size;

	size = -2;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (argc >= 2)
		size = parse_stack(argv, &stack_a, 'c');
	if (size == -1)
	{
		ft_printf("Error\n");
		free(stack_a);
		return (0);
	}
	if (argc >= 2)
		a = create_stack(&a, size, stack_a);
	parse_command(&a, &b, &fl);
	fresh_c(a, b, stack_a);
	return (0);
}
