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
    ft_putchar('\n');
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
    //swap_a(&a);
    //reverse_stack(&a);
    //swap_ss(&a,&b);
    //rra(&a);

    print_list(a);
    pb(&a,&b);
    pb(&a,&b);
    pb(&a,&b);
    printf("__________________\n");
    printf("stack_b\n");
//    print_list(b);
//    printf("\n");
   // swap_a(&b);
   // reverse_stack(&b);
    print_list(b);
    pa(&a,&b);
    print_list(b);
    print_list(a);
    free(head);

    return (0);
}