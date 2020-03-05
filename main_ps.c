/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:57:45 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:57:50 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack		*sort(t_stack *a, t_stack *b, int count_a, t_bonus *fl)
{
	if (if_sorted(&a, &b))
		return (a);
	if (count_a == 2)
		sort_two(&a, &b, fl);
	else if (count_a == 3)
		sort_three(&a, &b, fl);
	else if (count_a >= 4 && count_a < 70)
		insert_sort(&a, &b, fl);
	else
		sorting(&a, &b, fl, count_a);
	return (a);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*head;
	t_bonus	*fl;
	int		count_a;

	b = NULL;
	fl = NULL;
	fl = parse_flags(argv, fl);
	if (argc >= 2)
		a = create_stack(&head, argv, argc, fl);
	else
		return (ft_printf("Info: ./push_swap --help\n"));
	count_a = lst_count(&a);
	if (fl->flag_v && if_sorted(&a, &b))
	{
		print_bonus(a, b, fl);
		return (0);
	}
	a = sort(a, b, count_a, fl);
	free(fl);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
