/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:58:46 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:58:48 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	t_stack	*last;
	t_stack	*ptr;

	if (*a == NULL || a == NULL || lst_count(a) == 1)
		return ;
	ptr = *a;
	while (ptr->next != NULL)
	{
		last = ptr;
		ptr = ptr->next;
	}
	last->next = NULL;
	ptr->next = (*a);
	*a = ptr;
	last->next = NULL;
	(fl)->command = "rra\n";
	if (fl->flag_v)
		print_bonus(*a, *b, fl);
}

void		rrb_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	fl->command = "rrb\n";
	rra_nw(a, b, fl);
}

void		rra(t_stack **a, t_stack **b, t_bonus *fl)
{
	rra_nw(a, b, fl);
	if (!(fl->flag_v))
		ft_putstr("rra\n");
}

void		rrb(t_stack **a, t_stack **b, t_bonus *fl)
{
	rra_nw(b, a, fl);
	if (!(fl->flag_v))
		ft_putstr("rrb\n");
}
