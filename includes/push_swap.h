/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:58:33 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/04 18:58:34 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/headers/libft.h"
# include "libft/headers/get_next_line.h"
# include "libft/headers/ft_printf.h"
# include <stdio.h>
# define INTERVAL_HUNDRED	5
# define INTERVAL_FIVE_HUNDRED	12
# define INTERVAL_MORE	20
# define BLACK	"\033[1;30m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define CYAN	"\033[1;35m"
# define PURPLE	"\033[1;36m"
# define WHITE	"\033[1;37m"
# define EOC	"\033[0;0m"

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_bonus
{
	char			*command;
	int				flag_v;
	int				flag_help;
	int				flag_ch;
	int				count_flag;
}					t_bonus;
void				print_list(t_stack *n);
long long			ft_atoi_ps(char ***str, t_stack **a, t_stack **b);
void				free_stack(t_stack **head);
int					get_next_line(const int fd, char **line);
void				parse_command(t_stack **a, t_stack **b, t_bonus *fl,
		int *stack_a);
void				more_int(long long int nb);
void				check_duplicate(t_stack *a, t_stack *b, int nbr);
int					lst_count(t_stack **a);
void				sa(t_stack **a, t_stack **b, t_bonus *fl);
void				sb(t_stack **b, t_stack **a, t_bonus *fl);
void				ss(t_stack **a, t_stack **b, t_bonus *fl);
void				ra(t_stack **a, t_stack **b, t_bonus *fl);
void				rb(t_stack **a, t_stack **b, t_bonus *fl);
void				rr(t_stack **a, t_stack **b, t_bonus *fl);
void				rra(t_stack **a, t_stack**b, t_bonus *fl);
void				rrb(t_stack **a, t_stack **b, t_bonus *fl);
void				rrr(t_stack **a, t_stack **b, t_bonus *fl);
void				pa(t_stack **a, t_stack **b, t_bonus *fl);
void				pb(t_stack **a, t_stack **b, t_bonus *fl);
void				sa_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				sb_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				ss_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				ra_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				rb_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				rr_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				rra_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				rrb_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				rrr_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				pa_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				pb_nw(t_stack **a, t_stack **b, t_bonus *fl);
void				sort_two(t_stack **a, t_stack **b, t_bonus *fl);
void				sort_three(t_stack **a, t_stack **b, t_bonus *fl);
void				sort_five(t_stack **a, t_stack **b, t_bonus *fl);
void				insert_sort(t_stack **a, t_stack **b, t_bonus *fl);
void				sorting(t_stack **a, t_stack **b, t_bonus *fl, int count_a);
int					if_sorted(t_stack **a, t_stack **b);
int					if_reverse_sorted(t_stack **b);
int					max_of_stack(t_stack **head);
int					min_of_stack(t_stack **head);
void				baraban_a(t_stack **a, t_stack **b, t_bonus *fl, int pos);
void				baraban_b(t_stack **b, t_stack **a, t_bonus *fl, int pos);
int					count_step(t_stack **head, int data);
int					min_of_stack(t_stack **head);
int					max_of_stack(t_stack **head);
void				print_ok(t_stack **a, t_stack **b, int *stack_a);
void				print_ko(t_stack **a, t_stack **b, int *stack_a);
void				print_error(t_stack **a, t_stack **b);
void				print_bonus(t_stack *a, t_stack *b, t_bonus *fl);
char				**parse_flags(char **argv, t_bonus *fl);
t_stack				*create_stack(t_stack **head, int argc, int *stack_a);
int					parse_stack(char **a, int **stack_a, char programm);
t_stack				*sort(t_stack *a, t_stack *b, int count_a, t_bonus *fl);
char				**parse_flags_c(char **argv, t_bonus *fl);
int					valid_arg(int argc, char **argv);
int					write_error(void);

#endif
