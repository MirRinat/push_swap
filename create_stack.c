/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:57:16 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 19:20:16 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		append_stack(t_stack **head, int number)
{
	t_stack	*new;
	t_stack	*last;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	last = *head;
	new->nb = number;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

t_stack		*create_stack(t_stack **head, int argc, t_bonus *fl, int *stack_a)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = *head;
	b = NULL;
	i = 0;
	if (fl && (fl)->flag_v)
		i = fl->count_flag + 1;
	while (i < argc)
	{
//		append_stack(&a, ft_atoi_ps(argv[i], &a, &b));
//		check_duplicate(a, b, ft_atoi_ps(argv[i], &a, &b));
        append_stack(&a, stack_a[i]);
        check_duplicate(a, b, stack_a[i]);
		i++;
	}
	return (a);
}
