/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:56:45 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:56:47 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	fl->command = "ss\n";
	sa_nw(a, b, fl);
	sb_nw(b, a, fl);
}

void	rr_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	ra_nw(a, b, fl);
	rb_nw(b, a, fl);
}

void	rrr_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
	rra_nw(a, b, fl);
	rrb_nw(b, a, fl);
}

void	rr(t_stack **a, t_stack **b, t_bonus *fl)
{
	ra_nw(a, b, fl);
	rb_nw(b, a, fl);
	if (!(fl->flag_v))
		ft_putstr("rr\n");
}

void	rrr(t_stack **a, t_stack **b, t_bonus *fl)
{
	rra_nw(a, b, fl);
	rrb_nw(b, a, fl);
	if (!(fl->flag_v))
		ft_putstr("rrr\n");
}
