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

static int				check_order(int *stack, int **stack_a,
		int size, char programm)
{
	int					i;

	i = 0;
	while (i < (size - 1))
	{
		if (stack[i] > stack[i + 1])
		{
			if (!(*stack_a = ft_digitmass_cpy(stack, size)))
				return (-1);
			return (size);
		}
		i++;
	}
	if (programm == 'c')
	{
		if (!(*stack_a = ft_digitmass_cpy(stack, size)))
			return (-1);
		return (size);
	}
	return (0);
}

static int				ft_atoi_p(char ***a, int minus)
{
	char				*star;
	long				result;
	long				rank_count;

	star = **a;
	result = 0;
	while (***a >= '0' && ***a <= '9' && ***a != '\0')
		(**a)++;
	while (*star == '0' && *(star + 1) == '0' && *star)
		(star)++;
	if (***a != ' ' && ***a != '\0')
		exit(ft_printf("\033[31mError\033[0m\n"));
	if (**a - star - 1 > 10)
		exit(ft_printf("\033[31mError\033[0m\n"));
	rank_count = ft_to_power(10, (**a - star - 1));
	while (rank_count > 0)
	{
		result += (*star - '0') * rank_count;
		star++;
		rank_count /= 10;
	}
	result *= (minus > 0) ? -1 : 1;
	if (result >= 2147483648 || result <= -2147483649)
		exit(ft_printf("\033[31mError\033[0m\n"));
	return (result);
}

static int				check_minus(char ***a)
{
	int					minus;
	int					plus;

	minus = 0;
	plus = 0;
	while (!(***a >= 48 && ***a <= 57) && ft_memchr("+-", ***a, 2))
	{
		if (***a == '-')
			minus = minus + 1;
		if (***a == '+')
			plus = plus + 1;
		if ((plus && minus) || plus > 1 || minus > 1)
			return (-1);
		(**a)++;
	}
	if (!(***a >= 48 && ***a <= 57))
		return (-1);
	return (minus);
}

int						parse_stack(char **a, int **stack_a, char programm)
{
	int					stack[1500];
	int					minus;
	int					size;

	size = 0;
	a++;
	ft_bzero(stack, sizeof(int) * 1500);
	while (*a != NULL)
	{
		while (**a != '\0')
		{
			while (**a == ' ')
				(*a)++;
			if (**a == '\0')
				break ;
			if ((minus = check_minus(&a)) == -1)
				return (-1);
			stack[size++] = ft_atoi_p(&a, minus);
		}
		a++;
	}
	size = check_order(stack, stack_a, size, programm);
	return (size);
}
