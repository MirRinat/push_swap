#include "push_swap.h"

int more_int(int nb)
{
    long long int small;

    small = -2147483648;
    if(nb > 2147483647)
    {
        ft_putstr("Error\n");
        return (1);
    }
    if (nb < small)
    {
        ft_putstr("Error\n");
        return (1);
    }
    return (0);
}

long long			ft_atoi_ps(const char *str)
{
    long long	r;
    long long	nb;

    r = 1;
    nb = 0;
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            r = -1;
        str++;
    }
    while (*str != '\0')
    {
        if (*str < 48 || *str > 57)
        {
            ft_putstr("Error\n");
            exit(1);
        }
        nb = nb * 10 + (*str - '0') * r;
        if (more_int(nb))
            exit(1);
        str++;
    }
    return (nb);
}

//t_stack *create_stack_for_checker(int argc, char **argv, t_stack **a)
//{
//    t_stack *head;
//
//}
//int main(int argc, char **argv)
//{
//    t_stack *a;
//    t_stack *b;
//
//    if (argc < 2)
//        return (0);
//
//
//}