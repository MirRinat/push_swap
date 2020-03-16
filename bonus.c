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

#include "includes/push_swap.h"

void		print_bonus(t_stack *a, t_stack *b, t_bonus *fl)
{
	ft_printf("\x1B[35mCommand\x1B[0m %s\n", (fl)->command);
	ft_putstr("\x1B[31mstack A:\x1B[0m [ ");
	if (a)
	{
		while (a->next)
		{
			ft_printf("%d | ", a->nb);
			a = a->next;
		}
		ft_printf("%d ", a->nb);
	}
	ft_printf("]\n\n%s", "\x1B[31mstack B:\x1B[0m [ ");
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

void		init_struct(char **argv, t_bonus *fl)
{
	fl->command = "";
	fl->flag_v = 0;
	fl->count_flag = 0;
	if (argv[1] && !ft_strcmp(argv[1], "--help"))
	{
		fl->count_flag++;
		ft_printf("./push_swap (unsorted stack)\tSort stack\n"
			"./checker (unsorted stack)\tCheck commands\n\n"\
		"-v\t\tPrint stacks after command\n"\
		"--clear\t\tClear window before sorting stacks\n"
		"-c\t\tView what command are doing(for checker)\n");
		exit(1);
	}
}

char		**parse_flags(char **argv, t_bonus *fl)
{
	char **ptr;

	ptr = argv;
	init_struct(argv, fl);
	if (argv[1] && (!ft_strcmp(argv[1], "-v") ||
	(!ft_strcmp(argv[2], "--clear"))))
	{
		if (!argv[2] && !argv[3])
		{
			ft_putstr("\033[31mError\033[0m\n");
			exit(1);
		}
		(fl)->count_flag++;
		(fl)->flag_v = 1;
		ptr++;
	}
	if ((!ft_strcmp(argv[2], "--clear")))
	{
		fl->count_flag++;
		system("clear");
		ptr++;
	}
	return (ptr);
}

char		**parse_flags_c(char **argv, t_bonus *fl)
{
	char **ptr;

	ptr = argv;
	init_struct(argv, fl);
	if (argv[1] && (!ft_strcmp(argv[1], "-c") ||
	(!ft_strcmp(argv[2], "--clear"))))
	{
		if (!argv[2] && !argv[3])
		{
			ft_putstr("\033[31mError\033[0m\n");
			exit(1);
		}
		(fl)->count_flag++;
		(fl)->flag_ch = 1;
		ptr++;
	}
	if ((!ft_strcmp(argv[2], "--clear")))
	{
		fl->count_flag++;
		system("clear");
		ptr++;
	}
	return (ptr);
}
