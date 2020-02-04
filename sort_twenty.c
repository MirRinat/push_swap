#include "push_swap.h"

void push_min(t_stack **a,t_stack **b)
{
    int min;
    int pos_min;

    min = min_of_stack(&*a);
    pos_min = count_step(&*a,min);
    baraban(&*a,pos_min);
    pb(&*a,&*b);
}


void insert_sort(t_stack **a,t_stack **b)
{
    int len_a = lst_count(&*a);
    while(len_a > 3)
    {
        if (if_sorted(&*a))
            break;
        push_min(&*a,&*b);
        len_a--;
    }
    sort_three(&*a);
    while (*b)
        pa(&*a,&*b);
}