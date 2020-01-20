#include "push_swap.h"

void sa(t_stack **a)
{
    t_stack *b;
    t_stack *tmp;

    if (*a == NULL)
        return;
    b = (*a)->next;
    tmp = *a;
    (*a) = b;
    tmp->next = b->next;
    (*a)->next = tmp;
}

void sb(t_stack **a)
{
    sa(a);
}

void ss(t_stack **a,t_stack **b)
{
    sa(a);
    sb(b);
}

void ra(t_stack **head)
{
    t_stack *first;
    t_stack *last;

    if (*head == NULL)
        return;
    first = *head;
    last = *head;
    while (last->next != NULL)
        last = last->next;
    (*head) = (*head)->next;
    first->next = NULL;
    last->next = first;
}

void rb(t_stack **head)
{
    ra(head);
}

void rr(t_stack **a,t_stack **b)
{
    ra(a);
    rb(b);
}

void rra(t_stack **head)
{
    t_stack *last;
    t_stack *ptr;

    if (*head == NULL)
        return;
    ptr = *head;
    while (ptr->next != NULL)
    {
        last = ptr;
        ptr = ptr->next;
    }
    last->next = NULL;
    ptr->next = (*head);
    *head = ptr;
    last->next = NULL;
}

void rrb(t_stack **head)
{
    rra(head);
}

void rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rra(b);
}

void pa(t_stack **a,t_stack **b)
{
    t_stack *second;

    if (*b == NULL)
        return;
    second = (*b)->next;
    (*b)->next = *a;
    *a = *b;
    *b = second;
}

void pb(t_stack **a,t_stack **b)
{
    t_stack *second;

    if (*a == NULL)
        return;
    second = (*a)->next;
    (*a)->next = *b;
    *b = *a;
    *a = second;
}

