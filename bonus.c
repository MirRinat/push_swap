/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:26:05 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 19:26:19 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_bonus(t_stack *a, t_stack *b, t_bonus *fl)
{
	ft_printf("Command %s\n", (fl)->command);
	ft_printf("Stack A: [ ");
	if (a)
	{
		while (a->next)
		{
			ft_printf("%d | ", a->nb);
			a = a->next;
		}
		ft_printf("%d ", a->nb);
	}
	ft_printf("]\n\n%s", "Stack B: [ ");
	if (b != NULL)
	{
		while (b->next != NULL)
		{
			ft_printf("%d | ", b->nb);
			b = b->next;
		}
		ft_printf("%d ", b->nb);
	}
	ft_printf("]\n\n");
}

t_bonus		*init_struct(int argc, char **argv, t_bonus *fl)
{
	fl = (t_bonus *)malloc(sizeof(t_bonus));
	(fl)->command = "";
	(fl)->flag_v = 0;
	(fl)->count_flag = 0;
	if (argv[1] && !ft_strcmp(argv[1], "--help"))
	{
		(fl)->count_flag++;
		ft_printf("./push_swap (unsorted stack)\tSort stack\n\n"\
		"-v\t\tPrint stacks after command\n"\
		"--clear\t\tClear window before sorting stacks\n");
		free(fl);
		exit(1);
	}
}

t_bonus		*parse_flags(int argc, char **argv, t_bonus *fl)
{
	fl = init_struct(argc, argv, fl);
	if (argv[1] && (!ft_strcmp(argv[1], "-v") \
	|| !ft_strcmp(argv[1], "--clear")))
	{
		if (!argv[2])
		{
			ft_putstr("\033[31mError\033[0m\n");
			free(fl);
			exit(1);
		}
		(fl)->count_flag++;
		(fl)->flag_cl = 1;
		(fl)->flag_v = 1;
	}
	if (argv[2] && (!ft_strcmp(argv[2], "--clear")\
	|| !ft_strcmp(argv[2], "-v")))
	{
		fl->count_flag++;
		system("clear");
	}
	return (fl);
}
