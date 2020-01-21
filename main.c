#include <stdio.h>
#include "push_swap.h"


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
    printf("stack_a\n");
	print_list(a);
    if (argc == 4)
        sort_three(&a);
    print_list(a);
//
    printf("__________________\n");
    printf("stack_b\n");
    print_list(b);



    print_list(b);
    free(head);

    return (0);
}