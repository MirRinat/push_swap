#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *head;

    if (argc < 2)
        return (0);
    a = create_stack(&head,argv,argc);
    if (a == NULL)
        return (0);
    parse_command(&a,&b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}