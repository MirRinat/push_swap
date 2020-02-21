


#include "push_swap.h"

void  baraban_b(t_stack **head,int pos)
{
    int len = lst_count(&*head);
    int step;
    int step2;

    step = pos;
    step2 = len - pos;
    if (pos < len / 2)
        while(step)
        {
            rb(&*head);
            step--;
        }
    if (pos >= len / 2)
        while(step2)
        {
            rrb(&*head);
            step2--;
        }
}

void	min_max_b(t_stack **a, t_stack **b)
{
    long	b_largest;
    long	b_smallest;
    int		b_small_pos;

    b_largest = max_of_stack(&*b);
    b_smallest = min_of_stack(&*b);
    b_small_pos = count_step(&*b, b_smallest);
    if ((*a)->nb < b_smallest || (*a)->nb > b_largest)
    {
        baraban_b(b, b_small_pos);
        pb(a,b);
    }

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



void		rb_or_rrb_one_hun_two(t_stack **a, t_stack **b, int pos, int tot)
{
    int biggest;

    biggest = max_of_stack(&*b);
    while (tot > pos)
    {
        rrb(b);
        pos++;
    }
    if ((*b)->nb == biggest)
        pa(a, b);
}

void		rb_or_rrb_one_hun_one(t_stack **a, t_stack **b, int pos)
{
    while (pos > 0)
    {
        rb(b);
        pos--;
    }
    pa(a, b);
}

int		rb_or_rrb_one_hundered(t_stack **a, t_stack **b, int tot)
{
    int i;
    int half;
    int	pos;
    int biggest;

    i = 0;
    while (*b)
    {
        tot = lst_count(&*b);
        half = tot / 2;
        pos = 0;
        biggest = max_of_stack(&*b);
        pos = count_step(&*b,biggest);
        if (pos <= half)
            rb_or_rrb_one_hun_one(a, b, pos);
        if (pos > half)
           rb_or_rrb_one_hun_two(a, b, pos, tot);
    }
    return (i);
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

    while (range(*a, chunk) == 1)
    {
        range_pos = range_pos_funct(*a, chunk);
        if ((*a) && !((*a)->nb <= chunk))
            baraban(a, range_pos);
        if ((*a) && (*a)->nb <= chunk)
        {
            if (lst_count(&*b) == 1 || (!*b))
                pb(a, b);
        }
        if (lst_count(&*b) > 1 && (*a) && (*a)->nb <= chunk)
            min_max_b(a, b);
        if (lst_count(&*b) > 1 && (*a) && (*a)->nb <= chunk)
            before_push_b(a, b);
    }
}

void    sort_hundred(t_stack **a, t_stack **b)
{
    int interval;
    int	count_elem;
    int i;
    int chunk;

    i = 1;
    count_elem = lst_count(&*a);
    while (*a)
    {
        interval = count_elem / 5;
        chunk = interval * i++;
        if (range(*a, chunk))
           if_find_less_chunk(a, b,chunk);
    }
    if (!*a)
        rb_or_rrb_one_hundered(a, b, count_elem);
}


