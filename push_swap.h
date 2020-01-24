

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "./libft/libft.h"

typedef struct s_stack
{
    int nb;
    struct s_stack *next;
}               t_stack;

//create stack
void print_list(t_stack *n);
void reverse_stack(t_stack **head);
void append_stack(t_stack **head, int number);
void push_stack(t_stack **head,int number);
t_stack *create_stack(t_stack **head,char **argv,int argc);

//lst_commands
int lst_count(t_stack **a);

//commands

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

//sorting
void sort_three(t_stack **a);
void sort_five(t_stack **a,t_stack **b);
int if_sorted(t_stack **a);



#endif //PUSH_SWAP_PUSH_SWAP_H
