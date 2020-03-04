#include "push_swap.h"

//functions fot ss,rr,rrr

void sa_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
    t_stack *t;
    t_stack *tmp;

    if (*a == NULL || a == NULL || lst_count(a) == 1)
        return;
    t = (*a)->next;
    tmp = *a;
    (*a) = t;
    tmp->next = t->next;
    (*a)->next = tmp;
    (fl)->command = "sa\n";
    if (fl->flag_v)
        print_bonus(*a, *b, fl);
}

void sb_nw(t_stack **a, t_stack **b, t_bonus *fl)
{
    fl->command = "sb\n";
    sa_nw(b,a,fl);
}

void ss_nw(t_stack **a,t_stack **b, t_bonus *fl)
{
    fl->command = "ss\n";
    sa_nw(a,b,fl);
    sb_nw(b,a,fl);
}

void ra_nw(t_stack **a,t_stack **b,t_bonus *fl)
{
    t_stack *first;
    t_stack *last;

    if (*a == NULL || *a == NULL || lst_count(a) == 1)
        return;
    first = *a;
    last = *a;
    while (last->next != NULL)
        last = last->next;
    (*a) = (*a)->next;
    first->next = NULL;
    last->next = first;
    (fl)->command = "ra\n";
    if (fl->flag_v)
        print_bonus(*a, *b, fl);
}

void rb_nw(t_stack **a,t_stack **b,t_bonus *fl)
{
    fl->command = "rb\n";
    ra_nw(a,b,fl);
}

void rr_nw(t_stack **a,t_stack **b, t_bonus *fl)
{
    ra_nw(a,b,fl);
    rb_nw(b,a,fl);
}

void rra_nw(t_stack **a,t_stack **b, t_bonus *fl)
{
    t_stack *last;
    t_stack *ptr;

    if (*a == NULL || a == NULL || lst_count(a) == 1)
        return;
    ptr = *a;
    while (ptr->next != NULL)
    {
        last = ptr;
        ptr = ptr->next;
    }
    last->next = NULL;
    ptr->next = (*a);
    *a = ptr;
    last->next = NULL;
    (fl)->command = "rra\n";
    if (fl->flag_v)
        print_bonus(*a, *b, fl);
}

void rrb_nw(t_stack **a,t_stack **b, t_bonus *fl)
{
    fl->command = "rrb\n";
    rra_nw(a,b,fl);
}

void rrr_nw(t_stack **a,t_stack **b, t_bonus *fl)
{
    rra_nw(a,b,fl);
    rrb_nw(b,a,fl);
}

void pa_nw(t_stack **a,t_stack **b, t_bonus *fl)
{
    t_stack *second;

    if (*b == NULL || b == NULL)
        return;
    second = (*b)->next;
    (*b)->next = *a;
    *a = *b;
    *b = second;
    (fl)->command = "pa\n";
    if (fl->flag_v)
        print_bonus(*a, *b, fl);
}

void pb_nw(t_stack **a,t_stack **b, t_bonus *fl)
{
    t_stack *second;

    if (*a == NULL)
        return;
    second = (*a)->next;
    (*a)->next = *b;
    *b = *a;
    *a = second;
    (fl)->command = "pb\n";
    if (fl->flag_v)
        print_bonus(*a, *b, fl);
}




//##############################
//functions with write

void sa(t_stack **a, t_stack **b, t_bonus *fl)
{
    sa_nw(a,b,fl);
    if (!(fl->flag_v))
        ft_putstr("sa\n");
}

void sb(t_stack **b, t_stack **a, t_bonus *fl)
{
    sb_nw(b,a,fl);
    ft_putstr("sb\n");
}

void ss(t_stack **a,t_stack **b, t_bonus *fl)
{
    sa_nw(a,b,fl);
    sb_nw(b,a,fl);
    if (!(fl->flag_v))
        ft_putstr("ss\n");
}

void ra(t_stack **a,t_stack **b, t_bonus *fl)
{
	ra_nw(a,b,fl);
    if (!(fl->flag_v))
        ft_putstr("ra\n");
}

void rb(t_stack **a,t_stack **b, t_bonus *fl)
{
    ra_nw(b,a,fl);
    if (!(fl->flag_v))
        ft_putstr("rb\n");
}

void rr(t_stack **a,t_stack **b,t_bonus *fl)
{
    ra_nw(a,b,fl);
    rb_nw(b,a,fl);
    if (!(fl->flag_v))
        ft_putstr("rr\n");
}

void rra(t_stack **a,t_stack **b,t_bonus *fl)
{
	rra_nw(a,b,fl);
    if (!(fl->flag_v))
        ft_putstr("rra\n");
}

void rrb(t_stack **a, t_stack **b, t_bonus *fl)
{
    rra_nw(b,a,fl);
    if (!(fl->flag_v))
        ft_putstr("rrb\n");
}

void rrr(t_stack **a, t_stack **b, t_bonus *fl)
{
    rra_nw(a,b,fl);
    rrb_nw(b,a,fl);
    if (!(fl->flag_v))
        ft_putstr("rrr\n");
}

void pa(t_stack **a,t_stack **b, t_bonus *fl)
{
	pa_nw(a,b, fl);
    if (!(fl->flag_v))
        ft_putstr("pa\n");
}

void pb(t_stack **a,t_stack **b, t_bonus *fl)
{
	pb_nw(a,b, fl);
    if (!(fl->flag_v))
        ft_putstr("pb\n");
}

