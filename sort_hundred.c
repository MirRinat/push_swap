


#include "push_swap.h"

void  baraban_b(t_stack **head,int pos)
{
    int len;
    int step;
    int step2;

    len = lst_count(&*head);
    step = pos;
    step2 = len - pos;
    if (pos < len / 2)
        while(step--)
            rb(&*head);
    if (pos >= len / 2)
        while(step2--)
            rrb(&*head);
}

void	min_max_b(t_stack **a, t_stack **b)
{
    long	max_b;
    long	min_b;
    int		min_b_pos;
    int 	max_b_pos;

    max_b = max_of_stack(&*b);
    min_b = min_of_stack(&*b);
    min_b_pos = count_step(&*b, min_b);
    max_b_pos = count_step(&*b, max_b);
	baraban_b(b, max_b_pos);
	pb(a,b);
}


int find_pos_in_b(t_stack **a,t_stack **b)
{
    int pos;
    t_stack *ptr;

    pos = 0;
    ptr = *b;
    while(ptr && ptr->next)
    {
        pos++;
        if ((*a)->nb > ptr->nb && (*a)->nb < ptr->next->nb)
            return (pos);
        ptr = ptr->next;
    }
    return (pos);
}

void		before_push_a(t_stack **a, t_stack **b)
{
    int	pos;
    int biggest;

    while (*b)
    {
        biggest = max_of_stack(&*b);
        pos = count_step(&*b,biggest);
        if (lst_count(&*b) > 1)
            baraban_b(&*b,pos);
        pa(a,b);
    }
}


int		if_find_less_chunk(t_stack *a, int local_max)
{
    while (a)
    {
        if (a->nb <= local_max)
            return (1);
        a = a->next;
    }
    return (0);
}

int		range_pos_funct(t_stack *a, int local_max)
{
    int i;

    i = -1;
    while (a)
    {
        i++;
        if (a->nb <= local_max)
            return (i);
        a = a->next;
    }
    return (i);
}

void    before_push_b(t_stack **a, t_stack **b)
{
    int pos;

    pos = find_pos_in_b(a, b);
    baraban_b(b, pos);
    pb(a, b);
}

void    find_less_chunk(t_stack **a, t_stack **b, int chunk)
{
    int range_pos;

    while (if_find_less_chunk(*a, chunk))
    {
        range_pos = range_pos_funct(*a, chunk);
        if ((*a) && !((*a)->nb <= chunk))
            baraban_a(a, range_pos);
        if ((*a) && (*a)->nb <= chunk && (!(*b) || lst_count(&*b) == 1))
			pb(a,b);
        if (lst_count(&*b) > 1 && (*a) && (*a)->nb <= chunk)
            min_max_b(a, b);
        if (lst_count(&*b) > 1 && (*a) && (*a)->nb <= chunk)
            before_push_b(a, b);
    }
}

void    sorting(t_stack **a, t_stack **b, int count_a)
{
    int interval;
    int i;
    int chunk;

    i = 1;
    while (*a)
    {
    	if (count_a < 200)
        	interval = count_a / INTERVAL_HUNDRED;
		else if (count_a < 700)
			interval = count_a / INTERVAL_FIVE_HUNDRED;
		else
			interval = count_a / INTERVAL_MORE;
        chunk = interval * i++;
        if (if_find_less_chunk(*a, chunk))
           find_less_chunk(a, b,chunk);
    }
    before_push_a(a, b);
}


