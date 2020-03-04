/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:45:51 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 19:45:52 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_of_stack(t_stack **head)
{
	int	max;

	max = (*head)->nb;
	if (*head == NULL)
		return (0);
	while (*head)
	{
		if ((*head)->nb > max)
			max = (*head)->nb;
		head = &(*head)->next;
	}
	return (max);
}

int		min_of_stack(t_stack **head)
{
	int	min;

	min = (*head)->nb;
	if (*head == NULL)
		return (0);
	while (*head)
	{
		if ((*head)->nb < min)
			min = (*head)->nb;
		head = &(*head)->next;
	}
	return (min);
}

void	baraban_a(t_stack **a, t_stack **b, t_bonus *fl, int pos)
{
	int	len;
	int	step;
	int	step2;

	len = lst_count(&*a);
	step = pos;
	step2 = len - pos;
	if (pos < len / 2)
		while (step--)
			ra(&*a, &*b, fl);
	if (pos >= len / 2)
		while (step2--)
			rra(&*a, &*b, fl);
}

void	baraban_b(t_stack **b, t_stack **a, t_bonus *fl, int pos)
{
	int	len;
	int	step;
	int	step2;

	len = lst_count(&*b);
	step = pos;
	step2 = len - pos;
	if (pos < len / 2)
		while (step--)
			rb(&*a, &*b, fl);
	if (pos >= len / 2)
		while (step2--)
			rrb(&*a, &*b, fl);
}
