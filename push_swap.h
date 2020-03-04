

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
//#include "./ft_printf/includes/ft_printf.h"
#include <stdio.h>
#define	INTERVAL_HUNDRED	6
#define INTERVAL_FIVE_HUNDRED	12
#define INTERVAL_MORE	20

typedef struct s_stack
{
    int nb;
    struct s_stack *next;
}               t_stack;



typedef struct s_bonus
{
    char            *command;
    int             flag_v;
    int             flag_help;
    int             flag_cl;
    int             count_flag;
    char			bloc[200];
    char			line[46];
    char			spaces[200];
}               t_bonus;

//create stack
void print_list(t_stack *n);
void reverse_stack(t_stack **head);
//void append_stack(t_stack *head, int number);
void push_stack(t_stack **head,int number);
t_stack     *create_stack(t_stack **head,char **argv,int argc, t_bonus *val);
long long			ft_atoi_ps(const char *str,t_stack **a, t_stack **b);
void free_stack(t_stack **head);


//checker
int					get_next_line(const int fd, char **line);
void parse_command(t_stack **a, t_stack **b,t_bonus *fl);
void    more_int(long long int nb, t_stack **a, t_stack **b);
void		print_error(t_stack **a, t_stack **b);
void check_duplicate(t_stack *a,t_stack *b, int nbr);



//lst_commands
int lst_count(t_stack **a);

//commands
//with write
void sa(t_stack **a, t_stack **b, t_bonus *fl);
void sb(t_stack **b, t_stack **a, t_bonus *fl);
void ss(t_stack **a,t_stack **b, t_bonus *fl);
void ra(t_stack **a,t_stack **b, t_bonus *fl);
void rb(t_stack **a,t_stack **b, t_bonus *fl);
void rr(t_stack **a,t_stack **b,t_bonus *fl);
void rra(t_stack **a,t_stack**b,t_bonus *fl);
void rrb(t_stack **a, t_stack **b, t_bonus *fl);
void rrr(t_stack **a, t_stack **b, t_bonus *fl);
void pa(t_stack **a,t_stack **b, t_bonus *fl);
void pb(t_stack **a,t_stack **b, t_bonus *fl);


//without write
void sa_nw(t_stack **a, t_stack **b, t_bonus *fl);
void sb_nw(t_stack **a, t_stack **b, t_bonus *fl);
void ss_nw(t_stack **a, t_stack **b, t_bonus *fl);
void ra_nw(t_stack **a, t_stack **b,t_bonus *fl);
void rb_nw(t_stack **a, t_stack **b,t_bonus *fl);
void rr_nw(t_stack **a, t_stack **b, t_bonus *fl);
void rra_nw(t_stack **a, t_stack **b, t_bonus *fl);
void rrb_nw(t_stack **a,t_stack **b, t_bonus *fl);
void rrr_nw(t_stack **a,t_stack **b, t_bonus *fl);
void pa_nw(t_stack **a,t_stack **b, t_bonus *fl);
void pb_nw(t_stack **a,t_stack **b, t_bonus *fl);

//sorting
void sort_two(t_stack **a,t_stack **b, t_bonus *fl);
void sort_three(t_stack **a, t_stack **b, t_bonus *fl);
void sort_five(t_stack **a,t_stack **b, t_bonus *fl);
void insert_sort(t_stack **a,t_stack **b,t_bonus *fl);
void    sorting(t_stack **a, t_stack **b, t_bonus *fl, int count_a);
int if_sorted(t_stack **a, t_stack **b);
int if_reverse_sorted(t_stack **b);
int max_of_stack(t_stack **head);
int min_of_stack(t_stack **head);

//helper func
void  baraban_a(t_stack **a,t_stack **b, t_bonus *fl, int pos);
int count_step(t_stack **head,int data);
int min_of_stack(t_stack **head);
int max_of_stack(t_stack **head);

void quick_sort(t_stack **a, t_stack **b);



//bonus
void print_bonus(t_stack *a, t_stack *b, t_bonus *fl);

#endif //PUSH_SWAP_PUSH_SWAP_H
