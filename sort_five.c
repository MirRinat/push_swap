#include "push_swap.h"

t_stack *get_last(t_stack **head)
{
    t_stack *last;

    last = *head;
    if (*head == NULL)
        return(NULL);
    while (last->next)
    {
        last = last->next;
    }
    return (last);
}

t_stack *get_top(t_stack **head)
{
    return (*head);
}


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

    step = len - pos;
    if (step < (lst_count(&*head) / 2))
        while(step)
        {
            ra(&*head);
            step--;
        }
    if (step >= (lst_count(&*head) / 2))
        while(step)
        {
            rra(&*head);
            step--;
        }
    return (step);
}

int		sort_a_big_or_small(t_stack **a, t_stack **b)
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
        {
            sort_a_big_or_small(b, a);

        }
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


void sort_five(t_stack **a,t_stack **b) {

    int pos;
    int min;

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

}