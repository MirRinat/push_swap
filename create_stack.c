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


void free_stack(t_stack **head)
{
    t_stack *tmp;

    if (!*head || !head)
		return;

    while (*head)
    {
        tmp = *head;
        (*head) = (*head)->next;
        tmp->nb = 0;
        tmp->next = NULL;
        free(tmp);
    }
}

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

void push_stack(t_stack **head,int number)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->nb = number;
    new->next = (*head);
    (*head) = new;
}

void append_stack(t_stack **head, int number)
{
    t_stack *new;
    t_stack *last;

    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return;
    last = *head;
    new->nb = number;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    while(last->next)
        last = last->next;
    last->next = new;
}

int if_sorted(t_stack **a, t_stack **b)
{
    t_stack *ptr;

    ptr = *a;
    if (*b)
        return (0);
    while(ptr->next)
    {
        if (ptr->nb > ptr->next->nb)
            return (0);
        ptr = ptr->next;
    }
    return (1);
}


t_stack *create_stack(t_stack **head,char **argv,int argc, t_bonus *fl)
{
    t_stack *a;
    t_stack *b;
    int i;

    a = *head;
    b = NULL;
    i = 1;
    if (fl && (fl)->flag_v)
        i = fl->count_flag + 1;
    while(i < argc)
    {
        append_stack(&a,ft_atoi_ps(argv[i],&a,&b));
        check_duplicate(a,b,ft_atoi_ps(argv[i],&a,&b));
        i++;
    }
    return (a);
}