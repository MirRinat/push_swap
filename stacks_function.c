/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:49:29 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/05 14:49:37 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			lst_count(t_stack **a)
{
	t_stack	*ptr;
	int		count;

	ptr = *a;
	count = 0;
	if (!*a)
		return (0);
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

void		free_stack(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !head)
		return ;
	while (*head)
	{
		tmp = *head;
		(*head) = (*head)->next;
		tmp->nb = 0;
		tmp->next = NULL;
		free(tmp);
	}
}

int			if_sorted(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *a;
	if (*b)
		return (0);
	while (ptr->next)
	{
		if (ptr->nb > ptr->next->nb)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int			count_step(t_stack **head, int data)
{
	int		step;
	t_stack	*ptr;

	step = 0;
	ptr = *head;
	while (ptr->nb != data)
	{
		ptr = ptr->next;
		++step;
	}
	return (step);
}
