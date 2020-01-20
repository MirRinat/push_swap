#include <stdio.h>
#include "push_swap.h"

void print_list(t_stack *n)
{
    while (n)
    {
        ft_putnbr(n->nb);
        write(1," ",1);
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

t_stack *create_stack(t_stack **head,char **argv,int argc)
{
    t_stack *a;
    int i;
    int nb;

    i = 1;
    a = *head;
    while(i < argc)
    {
        append_stack(&a,ft_atoi(argv[i]));
        i++;
    }
    return (a);
}

void rotate_a(t_stack **a)
{
    t_stack *tmp;
    t_stack **ptr;
    t_stack *last;

    tmp = *a;
    ptr = &(*a)->next;
    while (*ptr && (*ptr)->next != NULL)
        ptr = &(*ptr)->next;
    (*a) = (*ptr);
    (*ptr) = tmp;

    (*a)->next = (*ptr)->next;
    (*ptr)->next = NULL;

}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *head = NULL;

    if (argc >= 2)
    {
        a = create_stack(&head,argv,argc);
        b = create_stack(&head,argv,argc);
    }
	print_list(a);
    printf("\n");
    //swap_a(&a);
    //reverse_stack(&a);
    //swap_ss(&a,&b);
    rotate_a(&a);
    print_list(a);

    printf("\n__________________\n");

//    print_list(b);
//    printf("\n");
   // swap_a(&b);
   // reverse_stack(&b);
//    print_list(b);
    free(head);
    return (0);
}