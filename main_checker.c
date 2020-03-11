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

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bonus fl;
	int *stack_a;
	int size;

	size = parse_stack(argv,&stack_a,'p');
	if (argc < 2)
		return (0);
	a = create_stack(&a, argc, &fl,stack_a);
	b = NULL;
	if (a == NULL)
		return (0);
	parse_command(&a, &b, &fl);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
