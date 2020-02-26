#include "push_swap.h"


void free_stack(t_stack **head)
{
    t_stack *tmp;

    while (*head)
    {
        tmp = *head;
        (*head) = (*head)->next;
        tmp->nb = 0;
        tmp->next = NULL;
        free(tmp);
    }
}

//int if_sorted(t_stack **a, t_stack **b)
//{
//    t_stack *ptr;
//
//    ptr = *a;
//    if (*b)
//        return (0);
//    while(ptr->next)
//    {
//        if (ptr->nb > ptr->next->nb)
//            return (0);
//        ptr = ptr->next;
//    }
//    return (1);
//}

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
    new->nb = number;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    last = *head;
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

//long long			ft_atoi_ps(const char *str,t_stack **a, t_stack **b)
//{
//    long long	r;
//    long long	nb;
//
//    r = 1;
//    nb = 0;
//    while ((*str >= 9 && *str <= 13) || *str == 32)
//        str++;
//    if (*str == '-' || *str == '+')
//    {
//        if (*str == '-')
//            r = -1;
//        str++;
//    }
//    while (*str != '\0')
//    {
//        if (*str < 48 || *str > 57)
//            print_error(a,b);
//        nb = nb * 10 + (*str - '0') * r;
//        str++;
//    }
//    nb *= r;
//    more_int(nb,a,b);
//    return (nb);
//}
//

t_stack *create_stack(t_stack **head,char **argv,int argc)
{
    t_stack *a;
    t_stack *b;

    b = NULL;
    int i;

    i = 1;

    if (!(a = (t_stack *)malloc(sizeof(t_stack))))
        return(0);
    a->nb = ft_atoi(argv[i++]);
    a->next = NULL;
    while(i < argc)
    {
        append_stack(&a,ft_atoi_ps(argv[i],&a,&b));
        i++;
    }
    return (a);
}