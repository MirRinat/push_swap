#include "push_swap.h"

//functions fot ss,rr,rrr

void sa_nw(t_stack **a)
{
    t_stack *b;
    t_stack *tmp;

    if (*a == NULL || a == NULL || lst_count(a) == 1)
        return;
    b = (*a)->next;
    tmp = *a;
    (*a) = b;
    tmp->next = b->next;
    (*a)->next = tmp;
}

void sb_nw(t_stack **a)
{
    sa_nw(a);
}

void ss_nw(t_stack **a,t_stack **b)
{
    sa_nw(a);
    sb_nw(b);
}

void ra_nw(t_stack **head)
{
    t_stack *first;
    t_stack *last;

    if (*head == NULL || *head == NULL || lst_count(head) == 1)
        return;
    first = *head;
    last = *head;
    while (last->next != NULL)
        last = last->next;
    (*head) = (*head)->next;
    first->next = NULL;
    last->next = first;
}

void rb_nw(t_stack **head)
{
    ra_nw(head);
}

void rr_nw(t_stack **a,t_stack **b)
{
    ra_nw(a);
    rb_nw(b);
}

void rra_nw(t_stack **head)
{
    t_stack *last;
    t_stack *ptr;

    if (*head == NULL || head == NULL || lst_count(head) == 1)
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

void rrb_nw(t_stack **head)
{
    rra_nw(head);
}

void rrr_nw(t_stack **a,t_stack **b)
{
    rra_nw(a);
    rrb_nw(b);
}

void pa_nw(t_stack **a,t_stack **b)
{
    t_stack *second;

    if (*b == NULL || b == NULL)
        return;
    second = (*b)->next;
    (*b)->next = *a;
    *a = *b;
    *b = second;
}

void pb_nw(t_stack **a,t_stack **b)
{
    t_stack *second;

    if (*a == NULL)
        return;
    second = (*a)->next;
    (*a)->next = *b;
    *b = *a;
    *a = second;
}




//##############################
//functions with write


void sa(t_stack **a)
{
    t_stack *b;
    t_stack *tmp;

    if (*a == NULL || a == NULL || lst_count(a) == 1)
        return;
    b = (*a)->next;
    tmp = *a;
    (*a) = b;
    tmp->next = b->next;
    (*a)->next = tmp;
    ft_putstr("sa\n");
}

void sb(t_stack **a)
{
    sa_nw(a);
    ft_putstr("sb\n");
}

void ss(t_stack **a,t_stack **b)
{
    sa_nw(a);
    sb_nw(b);
    ft_putstr("ss\n");
}

void ra(t_stack **head)
{
//    t_stack *first;
//    t_stack *last;
//
//    if (*head == NULL || head == NULL)
//        return;
//    first = *head;
//    last = *head;
//    while (last->next != NULL)
//        last = last->next;
//    (*head) = (*head)->next;
//    first->next = NULL;
//    last->next = first;
	ra_nw(head);
    ft_putstr("ra\n");
}

void rb(t_stack **head)
{
    ra_nw(head);
    ft_putstr("rb\n");
}

void rr(t_stack **a,t_stack **b)
{
    ra_nw(a);
    rb_nw(b);
    ft_putstr("rr\n");
}

void rra(t_stack **head)
{
//    t_stack *last;
//    t_stack *ptr;
//
//    if (*head == NULL || head == NULL)
//        return;
//    ptr = *head;
//    while (ptr->next != NULL)
//    {
//        last = ptr;
//        ptr = ptr->next;
//    }
//    last->next = NULL;
//    ptr->next = (*head);
//    *head = ptr;
//    last->next = NULL;
	rra_nw(head);
    ft_putstr("rra\n");
}

void rrb(t_stack **head)
{
    rra_nw(head);
    ft_putstr("rrb\n");
}

void rrr(t_stack **a, t_stack **b)
{
    rra_nw(a);
    rrb_nw(b);
    ft_putstr("rrr\n");
}

void pa(t_stack **a,t_stack **b)
{
//    t_stack *second;
//
//    if (*b == NULL)
//        return;
//    second = (*b)->next;
//    (*b)->next = *a;
//    *a = *b;
//    *b = second;
	pa_nw(a,b);
    ft_putstr("pa\n");
}

void pb(t_stack **a,t_stack **b)
{
//    t_stack *second;
//
//    if (*a == NULL)
//        return;
//    second = (*a)->next;
//    (*a)->next = *b;
//    *b = *a;
//    *a = second;
	pb_nw(a,b);
    ft_putstr("pb\n");
}

