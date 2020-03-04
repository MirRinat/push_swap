#include "push_swap.h"


void print_bonus(t_stack *a, t_stack *b,t_bonus *fl)
{
    printf("Command - %s\n", (fl)->command);
    ft_putstr("Stack A: [ ");
    if (a)
    {
        while (a->next)
        {
            printf("%d | ", a->nb);
            a = a->next;
        }
        printf("%d ", a->nb);
    }
    printf("]\n\n%s", "Stack B: [ ");
    if (b != NULL)
    {
        while (b->next != NULL)
        {
            printf("%d | ", b->nb);
            b = b->next;
        }
        printf("%d ", b->nb);
    }
    printf("]\n\n");
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_bonus *fl = (t_bonus *)malloc(sizeof(t_bonus));

    if (argc < 2)
        return (0);
    a = create_stack(&a,argv,argc,fl);
    b = NULL;
    if (a == NULL)
        return (0);
    parse_command(&a,&b,fl);
    free(fl);
    free_stack(&a);
    free_stack(&b);
    return (0);
}