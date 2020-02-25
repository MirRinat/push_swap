#include "push_swap.h"


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

void  baraban_a(t_stack **head,int pos)
{
    int len = lst_count(&*head);
    int step;
    int step2;

    step = pos;
    step2 = len - pos;
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
}

void	min_max_a(t_stack **a, t_stack **b)
{
    long	max_a;
    long	min_a;
    int		min_a_pos;

    max_a = max_of_stack(&*a);
    min_a = min_of_stack(&*a);
    min_a_pos = count_step(&*a, min_a);
    baraban_a(a, min_a_pos);
}



int find_pos_in_a(t_stack **a,t_stack **b)
{
    int pos;
    t_stack *ptr;

    pos = 0;
    ptr = *a;
    while(ptr && ptr->next)
    {
        pos++;
        if(ptr->next && (*b)->nb > ptr->nb && (*b)->nb < ptr->next->nb)
            return (pos);
        ptr = ptr->next;
    }
    return (pos);
}


void sort_five(t_stack **a,t_stack **b) {

    int pos;
    int min;

    while (lst_count(&*a) > 3)
        pb(a, b);
    sort_three(&*a);
    while (lst_count(&*b))
    {
        if ((*b)->nb > max_of_stack(a) || (*b)->nb < min_of_stack(a))
            min_max_a(a, b);
        pos = find_pos_in_a(a,b);
        baraban_a(a,pos);
        pa(&*a,&*b);
    }
    min = min_of_stack(a);
    pos = count_step(&*a,min);
    baraban_a(a,pos);
}