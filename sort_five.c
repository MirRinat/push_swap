#include "push_swap.h"

int count_step(t_stack **head,int data)
{
    int step;
    t_stack *ptr;

    step = 0;
    while(ptr->nb != data)
    {
        ptr = ptr->next;
        if (ptr == *head)
            ptr = ptr->next;
        ++step;
    }
    return (step);
}

void find_short_path(t_stack **head,int data)
{
    int step;

    step = count_step(&*head,data);
    if (step < (lst_count(*head) / 2))
        while((*head)->nb != data)
            rb(*head);
    else
        while((*head)->nb != data)
            rrb(*head);
}

void find_push(t_stack **a,t_stack **b,int data)
{
    int nb;
    t_stack *sec;

    sec = (*a)->next;
    nb = sec->nb;
    while(sec != *a)
    {
        if ((nb < data) || ((nb > sec->nb) && (sec->nb > data)))
            nb = sec->nb;
        sec = sec->next;
    }
    if (nb < data)
    {
        find_short_path(*a,(*a)->next->nb);
        pa(a,b);
    }
}


void sort_five(t_stack **a,t_stack **b) {
    t_stack *head_a = *a;
    t_stack *head_b = *b;

    while (lst_count(&*a) > 3)
        pb(a, b);
    while (lst_count(&*b))
    {
      find_push(head_a,head_b->nb);
    }
}