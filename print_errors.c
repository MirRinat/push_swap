/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:46:27 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:58:11 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_ok(t_stack **a, t_stack **b)
{
	ft_putstr("\033[32mOK\033[0m\n");
	free_stack(a);
	free_stack(b);
	exit(1);
}

void			print_ko(t_stack **a, t_stack **b)
{
	ft_putstr("\033[31mKO\033[0m\n");
	free_stack(a);
	free_stack(b);
	exit(1);
}

void			print_error(t_stack **a, t_stack **b)
{
	ft_putstr("\033[31mError\033[0m\n");
	free_stack(a);
	free_stack(b);
	exit(1);
}
