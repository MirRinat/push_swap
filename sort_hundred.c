
#include "push_swap.h"

void  baraban_b(t_stack **b,t_stack **a, t_bonus *fl, int pos)
{
    int len;
    int step;
    int step2;

    len = lst_count(&*b);
    step = pos;
    step2 = len - pos;
    if (pos < len / 2)
        while(step--)
            rb(&*a,&*b,fl);
    if (pos >= len / 2)
        while(step2--)
            rrb(&*a, &*b, fl);
}

void		before_push_a(t_stack **a, t_stack **b, t_bonus *fl)
{
    int	pos;
    int max_b;

    while (*b)
    {
        max_b = max_of_stack(&*b);
        pos = count_step(&*b,max_b);
        if (lst_count(&*b) > 1)
            baraban_b(&*b,&*a,fl,pos);
        pa(a,b, fl);
    }
}


int		if_find_less_chunk(t_stack *a, int chunk)
{
    while (a)
    {
        if (a->nb <= chunk)
            return (1);
        a = a->next;
    }
    return (0);
}

int		less_pos_funct(t_stack *a, int chunk)
{
    int pos;

    pos = 0;
    while (a)
    {
        if (a->nb <= chunk)
            return (pos);
        a = a->next;
        pos++;
    }
    return (pos);
}

void    find_less_chunk(t_stack **a, t_stack **b, t_bonus *fl,int chunk)
{
    int less_pos;

    while (if_find_less_chunk(*a, chunk))
    {
        less_pos = less_pos_funct(*a, chunk);

        baraban_a(a,b,fl,less_pos);
        pb(a, b, fl);
    }
}

void    sorting(t_stack **a, t_stack **b, t_bonus *fl, int count_a)
{
    int interval;
    int i;
    int chunk;

    i = 1;
    while(*a)
    {
    	if (count_a < 200)
        	interval = count_a / INTERVAL_HUNDRED;
		else if (count_a < 700)
			interval = count_a / INTERVAL_FIVE_HUNDRED;
		else
			interval = count_a / INTERVAL_MORE;
        chunk = interval * i++;
        if (if_find_less_chunk(*a, chunk))
           find_less_chunk(a, b,fl,chunk);
    }
    before_push_a(a, b,fl);
}


