#include "push_swap.h"

void sort_two(t_stack **a, t_stack **b, t_bonus *fl)
{
    int f;
    int s;

    f = a[0]->nb;
    s = a[0]->next->nb;
    if (s < f)
        sa_nw_bonus(a,b, fl);
}

void sort_three(t_stack **a)
{
    int first;
    int second;
    int third;

    first = a[0]->nb;
    second = a[0]->next->nb;
    third = a[0]->next->next->nb;
    if ((first > second) && (first < third))
        sa(a);
    else if ((first < second) && (first > third))
        rra(a);
    else if ((first < second) && (second > third))
    {
        rra(a);
        sa(a);
    }
    else if ((first > second) && (second < third))
        ra(a);
    else if ((first > second) && (second > third))
    {
        ra(a);
        sa(a);
    }
}
