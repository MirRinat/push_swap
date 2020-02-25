


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
    long	b_largest;
    long	b_smallest;
    int		b_small_pos;
    int 	b_largest_pos;

    b_largest = max_of_stack(&*b);
    b_smallest = min_of_stack(&*b);
    b_small_pos = count_step(&*b, b_smallest);
	b_largest_pos = count_step(&*b, b_largest);
	baraban_b(b, b_largest_pos);
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

void		rb_or_rrb_one_hundered(t_stack **a, t_stack **b)
{
    int	pos;
    int biggest;
    int tot;

    while (*b)
    {
        tot = lst_count(&*b);
        biggest = max_of_stack(&*b);
        pos = count_step(&*b,biggest);
        if (pos < tot / 2)
		{
        	while (pos-- > 0)
				rb(b);
        	pa(a,b);
		}
        if (pos >= tot / 2)
		{
        	while(pos++ < tot)
				rrb(b);
			pa(a,b);
		}
    }
}


int		range(t_stack *a, int local_max)
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

void    if_find_less_chunk(t_stack **a, t_stack **b, int chunk)
{
    int range_pos;

    while (range(*a, chunk))
    {
        range_pos = range_pos_funct(*a, chunk);
        if ((*a) && !((*a)->nb <= chunk))
            baraban(a, range_pos);
        if ((*a) && (*a)->nb <= chunk && (!(*b) || lst_count(&*b) == 1))
			pb(a,b);
        if (lst_count(&*b) > 1 && (*a) && (*a)->nb <= chunk)
            min_max_b(a, b);
        if (lst_count(&*b) > 1 && (*a) && (*a)->nb <= chunk)
            before_push_b(a, b);
    }
}

void    sort(t_stack **a, t_stack **b, int count_a)
{
    int interval;
    int	count_b;
    int i;
    int chunk;

    i = 1;
    count_b = lst_count(&*b);
    while (*a)
    {
    	if (count_a < 200)
        	interval = count_a / INTERVAL_HUNDRED;
		else if (count_a < 700)
			interval = count_a / INTERVAL_FIVE_HUNDRED;
		else
			interval = count_a / INTERVAL_MORE;
        chunk = interval * i++;
        if (range(*a, chunk))
           if_find_less_chunk(a, b,chunk);
    }
    if (!*a)
        rb_or_rrb_one_hundered(a, b);
}


