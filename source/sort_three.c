/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:36 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:59:37 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_two(t_stack **a, t_stack **b, t_bonus *fl)
{
	int		f;
	int		s;

	f = a[0]->nb;
	s = a[0]->next->nb;
	if (s < f)
		sa(a, b, fl);
}

void		sort_three(t_stack **a, t_stack **b, t_bonus *fl)
{
	int		first;
	int		second;
	int		third;

	first = a[0]->nb;
	second = a[0]->next->nb;
	third = a[0]->next->next->nb;
	if ((first > second) && (first < third))
		sa(a, b, fl);
	else if ((first < second) && (first > third))
		rra(a, b, fl);
	else if ((first < second) && (second > third))
	{
		rra(a, b, fl);
		sa(a, b, fl);
	}
	else if ((first > second) && (second < third))
		ra(a, b, fl);
	else if ((first > second) && (second > third))
	{
		ra(a, b, fl);
		sa(a, b, fl);
	}
}
