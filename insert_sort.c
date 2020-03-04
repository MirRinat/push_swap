/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:57:32 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:57:33 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **a, t_stack **b, t_bonus *fl)
{
	int	min;
	int	pos_min;

	min = min_of_stack(&*a);
	pos_min = count_step(&*a, min);
	baraban_a(&*a, &*b, fl, pos_min);
	pb(&*a, &*b, fl);
}

void	insert_sort(t_stack **a, t_stack **b, t_bonus *fl)
{
	int len_a;

	len_a = lst_count(&*a);
	while (len_a > 3)
	{
		if (if_sorted(&*a, &*b))
			break ;
		push_min(&*a, &*b, fl);
		len_a--;
	}
	sort_three(&*a, &*b, fl);
	while (*b)
		pa(&*a, &*b, fl);
}
