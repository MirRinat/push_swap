/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:58:57 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:58:59 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ra_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	t_stack	*first;
	t_stack *last;

	if (*a == NULL || *a == NULL || lst_count(a) == 1)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	(*a) = (*a)->next;
	first->next = NULL;
	last->next = first;
	(fl)->command = "ra\n";
	if (fl->flag_v)
		print_bonus(*a, *b, fl);
}

void		rb_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	fl->command = "rb\n";
	ra_nw(a, b, fl);
}

void		ra(t_stack **a, t_stack **b, t_bonus *fl)
{
	ra_nw(a, b, fl);
	if (!(fl->flag_v))
		ft_putstr("ra\n");
}

void		rb(t_stack **a, t_stack **b, t_bonus *fl)
{
	ra_nw(b, a, fl);
	if (!(fl->flag_v))
		ft_putstr("rb\n");
}
