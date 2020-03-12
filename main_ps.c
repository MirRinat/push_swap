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





int			*ft_digitmass_cpy(int *stack, int size)
{
    int		*s_a;
    int		i;

    i = 0;
    s_a = (int*)malloc(sizeof(int) * size);
    if (!s_a)
        return (NULL);
    while (i < size)
    {
        s_a[i] = stack[i];
        i++;
    }
    return (s_a);
}

static int				dupl_zero(int *stack_a, int size)
{
    int					i;
    int					count_z;

    i = 0;
    count_z = 0;
    while (i < size)
    {
        if (stack_a[i++] == 0)
        {
            count_z++;
            if (count_z > 1)
                return (1);
        }
    }
    return (0);
}

static int				check_order(int *stack, int **stack_a,
                                      int size, char programm)
{
    int					i;

    i = 0;
    if (dupl_zero(stack, size) == 1)
        return (-1);
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

static int				define_num(char ***a, int minus)
{
    char				*star;
    long				result;
    long				rank_count;

    star = **a;
    result = 0;
    while (***a >= 48 && ***a <= 57 && ***a != '\0')
        (**a)++;
    while (*star == '0' && *(star + 1) == '0' && *star)
        (star)++;
    if (***a != ' ' && ***a != '\0')
        exit(ft_printf("Error\n"));
    if (**a - star - 1 > 10)
        exit(ft_printf("Error\n"));
    rank_count = ft_to_power(10, (**a - star - 1));
    while (rank_count > 0)
    {
        result += (*star - 48) * rank_count;
        star++;
        rank_count /= 10;
    }
    result *= (minus > 0) ? -1 : 1;
    if (result >= 2147483648 || result <= -2147483649)
        exit(ft_printf("Error\n"));
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
        minus = (***a == '-') ? minus + 1 : minus;
        plus = (***a == '+') ? plus + 1 : plus;
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
            stack[size++] = define_num(&a, minus);
        }
        a++;
    }
    size = check_order(stack, stack_a, size,programm);
    return (size);
}


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
