/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:02:03 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:28:20 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			what_command(char *str, t_stack **a, t_stack **b, t_bonus *fl)
{
	if (!ft_strcmp(str, "sa"))
		sa_nw(a, b, fl);
	else if (!ft_strcmp(str, "sb"))
		sb_nw(b, a, fl);
	else if (!ft_strcmp(str, "ss"))
		ss_nw(a, b, fl);
	else if (!ft_strcmp(str, "pa"))
		pa_nw(a, b, fl);
	else if (!ft_strcmp(str, "pb"))
		pb_nw(a, b, fl);
	else if (!ft_strcmp(str, "ra"))
		ra_nw(a, b, fl);
	else if (!ft_strcmp(str, "rb"))
		rb_nw(b, a, fl);
	else if (!ft_strcmp(str, "rr"))
		rr_nw(a, b, fl);
	else if (!ft_strcmp(str, "rra"))
		rra_nw(a, b, fl);
	else if (!ft_strcmp(str, "rrb"))
		rrb_nw(b, a, fl);
	else if (!ft_strcmp(str, "rrr"))
		rrr_nw(a, b, fl);
	else
		print_error(a, b);
}

int				valid_arg(int argc, char **argv)
{
	int			i;
	int			j;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isprint(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void			check_duplicate(t_stack *a, t_stack *b, int nbr)
{
	int			i;

	i = 0;
	while (a)
	{
		if (a->nb == nbr)
			i++;
		a = a->next;
	}
	if (i >= 2)
		print_error(&a, &b);
}

void			parse_command(t_stack **a, t_stack **b, t_bonus *fl,
		int *stack_a)
{
	char		*line;

	if (fl->flag_ch)
		print_bonus(*a, *b, fl);
	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, ""))
			break ;
		what_command(line, a, b, fl);
		if (fl->flag_ch)
			print_bonus(*a, *b, fl);
		free(line);
	}
	if (if_sorted(a, b))
		print_ok(a, b, stack_a);
	else
		print_ko(a, b, stack_a);
}
