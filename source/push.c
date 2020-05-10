/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:58:21 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:58:22 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pa_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	t_stack	*second;

	if (*b == NULL)
		return ;
	second = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = second;
	(fl)->command = "pa\n";
	if (fl->flag_v)
		print_bonus(*a, *b, fl);
}

void		pb_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	t_stack	*second;

	if (*a == NULL)
		return ;
	second = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = second;
	(fl)->command = "pb\n";
	if (fl->flag_v)
		print_bonus(*a, *b, fl);
}

void		pa(t_stack **a, t_stack **b, t_bonus *fl)
{
	pa_nw(a, b, fl);
	if (!(fl->flag_v))
		ft_putstr("pa\n");
}

void		pb(t_stack **a, t_stack **b, t_bonus *fl)
{
	pb_nw(a, b, fl);
	if (!(fl->flag_v))
		ft_putstr("pb\n");
}
