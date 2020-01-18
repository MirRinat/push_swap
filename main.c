#include <stdio.h>
#include "push_swap.h"

void print_list(t_stack *n)
{
    while (n)
    {
        printf("%d ", n->nb);
        n = n->next;
    }
}

void reverse_stack(t_stack **head)
{
	t_stack *prev;
	t_stack *current;
	t_stack *next;

	prev = NULL;
	current = *head;
	next = NULL;
	while(current != NULL)
	{
		//reverse
		next = current->next;
		current->next = prev;

		//переприсвоение
		prev = current;
		current = next;
	}
	*head = prev;
}



void append_stack(t_stack **head, int number)
{
	t_stack *new  = (t_stack *)malloc(sizeof(t_stack));
	t_stack *last = *head;

	new->nb = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return;
	}
	while(last->next != NULL)
		last = last->next;
	last->next = new;
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
    t_stack *a;
    t_stack *b;
    t_stack *head = NULL;

    i = 1;
    if (argc >= 2)
    {
        while(argv[i])
        {
			append_stack(&head,ft_atoi(argv[i]));
            //push_stack(&head,ft_atoi(argv[i]));
            i++;
        }
    }
	print_list(head);
    printf("\n");
    reverse_stack(&head);
    print_list(head);
    free(head);
    return (0);
}