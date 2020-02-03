#include "push_swap.h"

//t_stack *get_last(t_stack **head)
//{
//    t_stack *last;
//
//    last = *head;
//    if (*head == NULL)
//        return(NULL);
//    while (last->next)
//    {
//        last = last->next;
//    }
//    return (last);
//}
//
//t_stack *get_top(t_stack **head)
//{
//    return (*head);
//}


int max_of_stack(t_stack **head)
{
    int max;

    max = (*head)->nb;
    if (*head == NULL)
        return(0);
    while (*head)
    {
        if ((*head)->nb > max)
            max = (*head)->nb;
        head = &(*head)->next;
    }
    return (max);

}

int min_of_stack(t_stack **head)
{
    int min;

    min = (*head)->nb;
    if (*head == NULL)
        return(0);
    while (*head)
    {
        if ((*head)->nb < min)
            min = (*head)->nb;
        head = &(*head)->next;
    }
    return (min);
}



int count_step(t_stack **head,int data)
{
    int step;
    t_stack *ptr;

    step = 0;
    ptr = *head;
    while(ptr->nb != data)
    {
        ptr = ptr->next;
        ++step;
    }
    return (step);
}

int find_short_path(t_stack **head,int pos)
{
    int len = lst_count(&*head);
    int step;
    int i;
    int step2;
    step = pos;
    step2 = len - pos;
    i = step;
    if (pos < len / 2)
        while(step)
        {
            ra(&*head);
            step--;
        }
    if (pos >= len / 2)
        while(step2)
        {
            rra(&*head);
            step2--;
        }
    return (i);
}

int		if_not_found(t_stack **a, t_stack **b)
{
    long	b_largest;
    long	b_smallest;
    int		b_small_pos;
    int		i;

    i = 0;
    b_largest = max_of_stack(&*b);
    b_smallest = min_of_stack(&*b);
    b_small_pos = count_step(&*b, b_smallest);
    if ((*a)->nb < b_smallest || (*a)->nb > b_largest)
        i += find_short_path(b, b_small_pos);
    return (i);
}


int find_pos_in_a(t_stack **a,t_stack **b)
{
    int pos;
    t_stack *temp;

    pos = 0;
    temp = *a;
    if (*b)
    {
        if ((*b)->nb > max_of_stack(a) || (*b)->nb < min_of_stack(a))
            if_not_found(b, a);
        else
        {
            while(temp)
            {
                pos++;
                if(temp->next && (*b)->nb > temp->nb && (*b)->nb < temp->next->nb)
                    return (pos);
                temp = temp->next;
            }
        }
    }

    return (pos);
}

int		pos_finder_test(t_stack *a, int small)
{
    int	i;
    int	pos;

    i = 0;
    pos = 0;
    while (a)
    {
        if (small == a->nb)
            pos = i;
        i++;
        a = a->next;
    }
    return (pos);
}

void sort_five(t_stack **a,t_stack **b) {

    int pos;
    int min;
    int  i = 0;

    pos = 0;
    min = 0;
    while (lst_count(&*a) > 3)
        pb(a, b);
    sort_three(&*a);
    while (lst_count(&*b))
    {
        pos = find_pos_in_a(a,b);
        find_short_path(a,pos);
        pa(&*a,&*b);
    }
    min = min_of_stack(a);
    pos = pos_finder_test(*a,min);
    i = find_short_path(a,pos);
}