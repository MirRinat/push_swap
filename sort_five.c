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

int count_step(t_stack **head,int data)
{
    int step;
    t_stack *ptr;

    step = 0;
    ptr = *head;
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
    if (step < (lst_count(&*head) >> 1))
        while((*head)->nb != data)
            ra(&*head);
    else
        while((*head)->nb != data)
            rra(&*head);
}

void find_push(t_stack **a,t_stack **b,int data)
{
    int nb;
    t_stack *sec;

    sec = (*a)->next;//sec = *a
    nb = sec->nb;
    while(sec->next) //sec.next != null
    {
        if ((nb < data) || ((nb > sec->nb) && (sec->nb > data)))
            nb = sec->nb;
        sec = sec->next;
    }
    if (nb < data)
    {
        find_short_path(&*a,(*a)->next->nb);
        pa(a,b);
    }
    if (nb > data)
    {
        find_short_path(&*a,nb);
        pa(a,b);
    }
}



void sort_five(t_stack **a,t_stack **b) {

    while (lst_count(&*a) > 3)
        pb(a, b);
    print_list(*a);
    sort_three(&*a);
    print_list(*b);
    while (lst_count(&*b))
    {
      find_push(&*a,&*b,(*b)->nb);
    }
    if (get_top(&*a) != get_top(&*a)->next)
    {
        while((get_top(&*a)->nb > get_last(&*a)->nb))
        {
            rra(&*a);
        }
    }
}