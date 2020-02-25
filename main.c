#include <stdio.h>
#include "push_swap.h"

void free_stack(t_stack **head)
{
    t_stack *tmp;

    while (*head)
    {
        tmp = *head;
        (*head) = (*head)->next;
        tmp->nb = 0;
        tmp->next = NULL;
        free(tmp);
    }
}

int lst_count(t_stack **a)
{
    t_stack *ptr;
    int count;

    ptr = *a;
    count = 0;
    if (!*a)
        return (0);
    while(ptr)
    {
        ptr = ptr->next;
        count++;
    }
    return (count);
}

int if_sorted(t_stack **a)
{
    t_stack *ptr;

    ptr = *a;
    while(ptr->next)
    {
        if (ptr->nb > ptr->next->nb)
            return (0);
        ptr = ptr->next;
    }
    return (1);
}
t_stack *sort(t_stack *a, t_stack *b, int count_a)
{
    if (if_sorted(&a))
        return(NULL);
    if (count_a == 2)
        sort_two(&a);
    else if (count_a == 3)
        sort_three(&a);
    else if (count_a >= 4 && count_a < 7)
        sort_five(&a,&b);
    else if (count_a >= 7 && count_a < 50)
        insert_sort(&a,&b);
    else
        sorting(&a,&b,count_a);
    return (a);
}



int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int count_a;
    t_stack *head;

    if (argc > 2)
        a = create_stack(&head,argv,argc);
    else
        return (0);
    count_a = lst_count(&a);
    a = sort(a,b,count_a);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
