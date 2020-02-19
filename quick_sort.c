#include "push_swap.h"







//##################################

//quick sort for stack a


void find_short_path_a(t_stack *head, int data)
{
    int step;
    int len;

    step = count_step(&head,data);
    len = lst_count(&head);
    if (step < len / 2)
    {
        while(head->nb != data)
            ra(&head);
    }
    else
    {
        while(head->nb != data)
            rra(&head);
    }
}


int less_than_pivot(t_stack **left, int *pivot)
{
    while ((*left)->next->nb ^ *pivot)
    {
        if ((*left)->nb < *pivot)
            return (1);
        *left = (*left)->next;
    }
    return (0);
}

void push_lower(t_stack **a,t_stack **b, t_stack **left, int *pushed, int *pivot)
{
    int step;
    int len;

    step = count_step(&*a,(*left)->nb);
    len = lst_count(&*a);
    if (step < len / 2)
    {
        while( *a != *left)
            ra(&*a);
    }
    else
    {
        rra(&*a);
        while( *a != *left)
        {
            if ((*a)->nb < *pivot)
            {
                pb(&*a,&*b);
                ++*pushed;
            }
            rra(&*a);
        }
    }
    pb(&*a, &*b);
    ++*pushed;
}


void		routine_a(t_stack **a, t_stack **b, int *pushed, int *pivot)
{
    find_short_path_a(*a,*pivot);
    if (!(if_sorted(&*a)
          && (if_reverse_sorted(&*b) || !lst_count(&*b))))
        pushed = 0;
    if (lst_count(&*a) > 2)
        pb(&*a,&*b);
}




void quicksort_a(t_stack **a, t_stack **b)
{
    int pivot;
    int pushed;
    t_stack *left;

    pushed = 0;
    while (lst_count(&*a))
    {
        pivot = (*a)->nb;
        (*a)->sorted = 1;
        left = (*a)->next;
        if (less_than_pivot(&left,&pivot))
        {
            push_lower(&*a, &*b, &left,&pushed,&pivot);
            if (if_sorted(&*a))
            {
                find_short_path_a(*a,(*a)->next->nb);
                break;
            }

        }
        else
            routine_a(&*a, &*b, &pushed, &pivot);
    }
}



// general quicksort


void quick_sort(t_stack **a, t_stack **b)
{
    while(!if_sorted(&*a))
    {
        quicksort_a(&*a, &*b);
        if (if_sorted(&*a) && (lst_count(&*b) || if_reverse_sorted(&*b)))
            break;
        find_short_path_a(*a,(*a)->next->nb);
        quicksort_b();
    }
    while(*b)
        pa(&*a, &*b);
}