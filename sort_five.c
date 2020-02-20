#include "push_swap.h"

//t_stack *get_last(t_stack **head)
//{
//    t_stack *last;
//
//    last = *head;
//    if (*head == NULL)
//        return(NULL);
//    while (last->next)
//    {
//        last = last->next;
//    }
//    return (last);
//}
//
//t_stack *get_top(t_stack **head)
//{
//    return (*head);
//}


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

void  baraban(t_stack **head,int pos)
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

void	min_max(t_stack **a, t_stack **b)
{
    long	a_largest;
    long	a_smallest;
    int		a_small_pos;

    a_largest = max_of_stack(&*a);
    a_smallest = min_of_stack(&*a);
    a_small_pos = count_step(&*a, a_smallest);
    if ((*b)->nb < a_smallest || (*b)->nb > a_largest)
        baraban(a, a_small_pos);
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
            min_max(a, b);
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

    while (lst_count(&*a) > 3)
        pb(a, b);
    sort_three(&*a);
    while (lst_count(&*b))
    {
        pos = find_pos_in_a(a,b);
        baraban(a,pos);
        pa(&*a,&*b);
    }
    min = min_of_stack(a);
    pos = count_step(&*a,min);
    baraban(a,pos);
}