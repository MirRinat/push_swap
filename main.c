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
    t_stack *head = NULL;

    if (argc >= 2)
        a = create_stack(&head,argv,argc);
    if (if_sorted(&a))
        return (0);
    printf("stack_a\n");
	print_list(a);
	if (if_sorted(&a))
    {
        printf("stack is sorted\n");
        return (0);
    }
    if (argc <= 3)
        sort_three(&a);
    if (argc >= 4 && argc <= 6)
        sort_five(&a,&b);
    if (argc >=7 && argc < 20)
        insert_sort(&a,&b);
    print_list(a);
    free(head);
    return (0);
}