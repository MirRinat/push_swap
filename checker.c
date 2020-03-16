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

#include "includes/push_swap.h"

void			what_command(char *str, t_stack **a, t_stack **b, t_bonus *fl, int *stack_a)
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
		print_error(a, b,stack_a);
}

void			more_int(long long int nb)
{
	if (nb > 2147483647 || nb < -2147483648)
	{
		ft_putstr("\033[31mError\033[0m\n");
		exit(1);
	}
}

long long		ft_atoi_ps(char ***str, t_stack **a, t_stack **b, int *stack_a)
{
	long long	r;
	long long	nb;

	r = 1;
	nb = 0;
	while ((***str >= 9 && ***str <= 13) || ***str == 32)
		str++;
	if (***str == '-' || ***str == '+')
	{
		if (***str == '-')
			r = -1;
        (**str)++;
		if (!ft_isdigit(***str))
			print_error(a, b, stack_a);
	}
	while (***str)
	{
		if (!ft_isdigit(***str))
			print_error(a, b, stack_a);
		nb = nb * 10 + (***str - '0');
		more_int(nb * r);
        (**str)++;
	}
	return (nb * r);
}

void			check_duplicate(t_stack *a, t_stack *b, int nbr, int *stack_a)
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
		print_error(&a, &b, stack_a);
}

void			parse_command(t_stack **a, t_stack **b, t_bonus *fl, int *stack_a)
{
	char		*line;

	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, ""))
			break ;
		what_command(line, a, b, fl, stack_a);
		if (fl->flag_ch)
		    print_bonus(*a,*b,fl);
		free(line);
	}
	if (if_sorted(a, b))
		print_ok(a, b,stack_a);
	else
		print_ko(a, b,stack_a);
}
