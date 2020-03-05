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
	t_bonus *fl;

	fl = (t_bonus *)malloc(sizeof(t_bonus));
	if (argc < 2)
		return (0);
	a = create_stack(&a, argv, argc, fl);
	b = NULL;
	if (a == NULL)
		return (0);
	parse_command(&a, &b, fl);
	free(fl);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
