

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "./libft/libft.h"
#define	INTERVAL_HUNDRED	5
#define INTERVAL_FIVE_HUNDRED	15
#define INTERVAL_MORE	20

typedef struct s_stack
{
    int nb;
    struct s_stack *next;
}               t_stack;

//create stack
void print_list(t_stack *n);
void reverse_stack(t_stack **head);
void append_stack(t_stack *head, int number);
void push_stack(t_stack **head,int number);
t_stack     *create_stack(t_stack **head,char **argv,int argc);
long long			ft_atoi_ps(const char *str,t_stack **a, t_stack **b);
void free_stack(t_stack **head);


int					get_next_line(const int fd, char **line);


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
