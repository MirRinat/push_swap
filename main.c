#include <stdio.h>
#include "push_swap.h"

void print_list(t_stack *n)
{
    while (n->next)
    {
        printf("%d ", n->nb);
        n = n->next;
    }
}




void push_stack(t_stack **head,int number)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));

    new->nb = number;
    new->next = (*head);
    (*head) = new;
}

int main(int argc, char **argv)
{
    int i;
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *head;

    head = (t_stack *)malloc(sizeof(t_stack));
    i = 1;
    if (argc >= 2)
    {
        while(argv[i])
        {
            push_stack(&head,ft_atoi(argv[i]));
            i++;
        }
        print_list(head);
    }
    free(head);
    return (0);
}