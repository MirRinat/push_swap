


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
    t_stack *temp;

    pos = 0;
    temp = *b;
    if (*b)
    {
            while(temp)
            {
                pos++;
                if(temp->next && (*a)->nb > temp->nb && (*a)->nb < temp->next->nb)
                    return (pos);
                temp = temp->next;
            }
        }
    return (pos);
}



int		rb_or_rrb_one_hun_two(t_stack **a, t_stack **b, int pos, int tot)
{
    int i;
    int biggest;

    i = 0;
    biggest = max_of_stack(&*b);
    while (tot > pos)
    {
        rrb(b);
//        write(1, "rrb\n", 4);
        pos++;
        i++;
    }
    if ((*b)->nb == biggest)
    {
        pa(a, b);
//        write(1, "pa\n", 3);
    }
    return (i);
}

int		rb_or_rrb_one_hun_one(t_stack **a, t_stack **b, int pos, int i)
{
    while (pos > 0)
    {
        rb(b);
//        write(1, "rb\n", 3);
        pos--;
        i++;
    }
    if (pos == 0)
    {
        pa(a, b);
//        write(1, "pa\n", 3);
        i++;
    }
    return (i);
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
            i += rb_or_rrb_one_hun_one(a, b, pos, i);
        if (pos > half)
            i += rb_or_rrb_one_hun_two(a, b, pos, tot);
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

//исправить расчет позиции
int		range_pos_funct(t_stack *a, int local_max)
{
    int pos_num;
    int i;

    pos_num = 0;
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

int		before_push_b(t_stack **a, t_stack **b)
{
    int pos;
    int i;

    i = 0;
    pos = find_pos_in_b(a, b);
    baraban_b(b, pos);
    pb(a, b);
    return (i);
}

int		if_find_less_chunk(t_stack **a, t_stack **b, int range_pos, int chunk)
{
    int len;
    int local_max;
    int i;
    int pos;

    len = lst_count(&*a);
    local_max = len / 5;
    i = 0;
    pos = 0;
    while (range(*a, chunk) == 1)
    {
        range_pos = range_pos_funct(*a, local_max);
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
            i += before_push_b(a, b);
    }
    return (i);
}

int		sort_hundred(t_stack **a, t_stack **b, int i)
{
    int local_max;
    int	tot;
    int j;
    int tot_div_chunk;
    int range_pos;

    j = 0;
    tot = lst_count(&*a);
    while (*a)
    {
        j++;
        local_max = tot / 5;
        tot_div_chunk = local_max * j;
        range_pos = range_pos_funct(*a, local_max);
        if (range(*a, tot_div_chunk) == 1)
            i += if_find_less_chunk(a, b, range_pos, tot_div_chunk);
//        printf("stack A = ");
//        print_list(*a);
//        printf("stack B = ");
//        print_list(*b);
    }
    if (!*a)
        i += rb_or_rrb_one_hundered(a, b, tot);
    return (i);
}


