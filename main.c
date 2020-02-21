#include <stdio.h>
#include "push_swap.h"


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

int if_reverse_sorted(t_stack **b)
{
    t_stack *ptr;

    ptr = *b;
    while(ptr->next)
    {
        if (ptr->nb < ptr->next->nb)
            return (0);
        ptr = ptr->next;
    }
    return (1);
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

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int count_a;
    t_stack *head = NULL;

    count_a = 0;
    if (argc >= 2)
        a = create_stack(&head,argv,argc);
	if (if_sorted(&a))
    {
        printf("stack is sorted\n");
        return (0);
    }
	count_a = lst_count(&a);
    print_list(a);
    if (count_a <= 3)
        sort_three(&a);
//    else if (count_a >= 4 && count_a <= 7)
//        sort_five(&a,&b);
//    else if (count_a >= 8 && count_a < 50)
//        insert_sort(&a,&b);
//    else if (count_a < 200)
    sort_hundred(&a,&b);
    print_list(a);
    free(head);
    return (0);
}
