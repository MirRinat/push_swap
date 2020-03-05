/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:13 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:59:15 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		min_max_a(t_stack **a, t_stack **b, t_bonus *fl)
{
	long	min_a;
	int		min_a_pos;

	min_a = min_of_stack(&*a);
	min_a_pos = count_step(&*a, min_a);
	baraban_a(a, b, fl, min_a_pos);
}

int			find_pos_in_a(t_stack **a, t_stack **b)
{
	int		pos;
	t_stack	*ptr;

	pos = 0;
	ptr = *a;
	while (ptr && ptr->next)
	{
		pos++;
		if (ptr->next && (*b)->nb > ptr->nb && (*b)->nb < ptr->next->nb)
			return (pos);
		ptr = ptr->next;
	}
	return (pos);
}
