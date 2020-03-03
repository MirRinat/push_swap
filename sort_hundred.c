


#include "push_swap.h"


//int max_of_stack_chunk(t_stack **head, int chunk)
//{
//    int max;
//
//    if ((*head)->nb >= chunk)
//        max = (*head)->nb;
//    else
//        max = -2147483648;
////    max = (*head)->nb;
////    max = -2147483648;
//    if (*head == NULL)
//        return(0);
//    while (*head)
//    {
//        if ((*head)->nb > max && (*head)->nb > chunk)
//            max = (*head)->nb;
//        head = &(*head)->next;
//    }
//    return (max);
//
//}
//
//int min_of_stack_chunk(t_stack **head, int chunk)
//{
//    int min;
//
////    min = (*head)->nb;
//    if ((*head)->nb <= chunk)
//        min = (*head)->nb;
//    else
//        min = 2147483647;
//    if (*head == NULL)
//        return(0);
//    while (*head)
//    {
//        if ((*head)->nb < min && (*head)->nb < chunk)
//            min = (*head)->nb;
//        head = &(*head)->next;
//    }
//    return (min);
//}

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

void	before_push_b(t_stack **a, t_stack **b)
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

void	before_push_b_one(t_stack **a, t_stack **b)
{
    long	min_b;
    int		min_b_pos;

    min_b = min_of_stack(&*a);
    min_b_pos = count_step(&*a, min_b);
    baraban_a(a, min_b_pos);
    pb(a,b);
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

void    find_less_chunk(t_stack **a, t_stack **b, int chunk)
{
    int less_pos;

    while (if_find_less_chunk(*a, chunk))
    {
        less_pos = less_pos_funct(*a, chunk);
        //if ((*a))// && !((*a)->nb <= chunk))
        baraban_a(a, less_pos);
        pb(a, b);
    }
}

void    sorting(t_stack **a, t_stack **b, int count_a)
{
    int interval;
    int i;
    int chunk;

    i = 1;
    while(*a) //(lst_count(&*a) > 15)
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
//    while (*a)
//       before_push_b_one(a,b);
    before_push_a(a, b);
}


