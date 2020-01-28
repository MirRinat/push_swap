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
    {
        a = create_stack(&head,argv,argc);
//        b = create_stack(&head,argv,argc);
    }
    if (if_sorted(&a))
        return (0);
    printf("stack_a\n");
	print_list(a);
//    if (argc <= 3)
//        sort_three(&a);
//    printf("count_lst a =%d\n",lst_count(&a));
    if (argc >=4 && argc <= 7)
        sort_five(&a,&b);
//    if (if_sorted(&a))
//        printf("stack is sorted\n");
//    else
//        printf("stack is not sorted\n");
//    printf("max stack = %d\n",max_of_stack(&a));
//    printf("min stack = %d\n",min_of_stack(&a));
    print_list(a);

    printf("__________________\n");
    printf("stack_b\n");
//    pb(&a,&b);
    print_list(b);



    print_list(b);
    free(head);

    return (0);
}