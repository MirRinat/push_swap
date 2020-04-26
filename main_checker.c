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

	a = NULL;
	b = NULL;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (valid_arg(argc, argv) == 0)
		exit(write_error());
	if (!ft_strcmp(argv[1], "-c") || !ft_strcmp(argv[1], "--help")
	|| !ft_strcmp(argv[2], "--clear"))
		argv = parse_flags_c(argv, &fl);
	size = parse_stack(argv, &stack_a, 'c');
	if (size == -1)
		print_error(&a, &b);
	if (argc >= 2)
		a = create_stack(&a, size, stack_a);
	parse_command(&a, &b, &fl, stack_a);
	fresh_c(a, b, stack_a);
	return (0);
}
