

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#define	INTERVAL_HUNDRED	6
#define INTERVAL_FIVE_HUNDRED	12
#define INTERVAL_MORE	20

typedef struct s_stack
{
    int nb;
    struct s_stack *next;
}               t_stack;



typedef struct s_values
{
    int				min;
    int				second_min;
    int				middle;
    int				max;
    int				size_a;
    int				size_b;
    int				v_flag;
    int				vz_flag;
    int				c_flag;
    int				size;
    int				pw;
    int				*order;
    int				miss_a;
    int				miss_b;
    char			bloc[200];
    char			line[46];
    char			spaces[200];
}               t_values;

//create stack
void print_list(t_stack *n);
void reverse_stack(t_stack **head);
//void append_stack(t_stack *head, int number);
void push_stack(t_stack **head,int number);
t_stack     *create_stack(t_stack **head,char **argv,int argc);
long long			ft_atoi_ps(const char *str,t_stack **a, t_stack **b);
void free_stack(t_stack **head);


//checker
int					get_next_line(const int fd, char **line);
void parse_command(t_stack **a, t_stack **b);
void    more_int(long long int nb, t_stack **a, t_stack **b);
void		print_error(t_stack **a, t_stack **b);
void check_duplicate(t_stack *a,t_stack *b, int nbr);



//lst_commands
int lst_count(t_stack **a);

//commands
//with write
void sa(t_stack **head);
void sb(t_stack **a);
void ss(t_stack **a,t_stack **b);
void ra(t_stack **head);
void rb(t_stack **head);
void rr(t_stack **a,t_stack **b);
void rra(t_stack **head);
void rrb(t_stack **head);
void rrr(t_stack **a, t_stack **b);
void pa(t_stack **a,t_stack **b);
void pb(t_stack **a,t_stack **b);


//without write
void sa_nw(t_stack **head);
void sb_nw(t_stack **a);
void ss_nw(t_stack **a,t_stack **b);
void ra_nw(t_stack **head);
void rb_nw(t_stack **head);
void rr_nw(t_stack **a,t_stack **b);
void rra_nw(t_stack **head);
void rrb_nw(t_stack **head);
void rrr_nw(t_stack **a, t_stack **b);
void pa_nw(t_stack **a,t_stack **b);
void pb_nw(t_stack **a,t_stack **b);

//sorting
void sort_two(t_stack **a);
void sort_three(t_stack **a);
void sort_five(t_stack **a,t_stack **b);
int if_sorted(t_stack **a, t_stack **b);
int if_reverse_sorted(t_stack **b);
int max_of_stack(t_stack **head);
int min_of_stack(t_stack **head);


void  baraban_a(t_stack **head,int pos);
int count_step(t_stack **head,int data);
int min_of_stack(t_stack **head);
int max_of_stack(t_stack **head);
void insert_sort(t_stack **a,t_stack **b);
void quick_sort(t_stack **a, t_stack **b);
void    sorting(t_stack **a, t_stack **b,int count_a);

#endif //PUSH_SWAP_PUSH_SWAP_H
