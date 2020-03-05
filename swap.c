/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:45 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:59:47 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		sa_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	t_stack	*t;
	t_stack	*tmp;

	if (*a == NULL || a == NULL || lst_count(a) == 1)
		return ;
	t = (*a)->next;
	tmp = *a;
	(*a) = t;
	tmp->next = t->next;
	(*a)->next = tmp;
	(fl)->command = "sa\n";
	if (fl->flag_v)
		print_bonus(*a, *b, fl);
}

void		sb_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	fl->command = "sb\n";
	sa_nw(b, a, fl);
}

void		sa(t_stack **a, t_stack **b, t_bonus *fl)
{
	sa_nw(a, b, fl);
	if (!(fl->flag_v))
		ft_putstr("sa\n");
}

void		sb(t_stack **b, t_stack **a, t_bonus *fl)
{
	sb_nw(b, a, fl);
	ft_putstr("sb\n");
}

void		ss(t_stack **a, t_stack **b, t_bonus *fl)
{
	sa_nw(a, b, fl);
	sb_nw(b, a, fl);
	if (!(fl->flag_v))
		ft_putstr("ss\n");
}
