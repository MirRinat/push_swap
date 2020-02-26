#include "push_swap.h"

void print_ok()
{
    ft_putstr("\33[32mOK\n");
    exit(1);
}

void print_ko(t_stack **a, t_stack **b)
{
    ft_putstr("\33[32mKO\n");
    free_stack(a);
    free_stack(b);
    exit(1);
}


int			is_space(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (1);
    return (0);
}

void		print_error(t_stack **a, t_stack **b)
{
    ft_putstr("\33[31mError\n");
    free_stack(a);
    free_stack(b);
    exit(1);
}

void		what_command(char *str, t_stack **a, t_stack **b)
{
    if (ft_strcmp(str, "sa") == 0)
        sa_nw(a);
    else if (ft_strcmp(str, "sb") == 0)
        sb_nw(b);
    else if (ft_strcmp(str, "ss") == 0)
        ss_nw(a, b);
    else if (ft_strcmp(str, "pa") == 0)
        pa_nw(a, b);
    else if (ft_strcmp(str, "pb") == 0)
        pb_nw(a, b);
    else if (ft_strcmp(str, "ra") == 0)
        ra_nw(a);
    else if (ft_strcmp(str, "rb") == 0)
        rb_nw(b);
    else if (ft_strcmp(str, "rr") == 0)
        rr_nw(a, b);
    else if (ft_strcmp(str, "rra") == 0)
        rra_nw(a);
    else if (ft_strcmp(str, "rrb") == 0)
        rrb_nw(b);
    else if (ft_strcmp(str, "rrr") == 0)
        rrr_nw(a, b);
    else
        print_error(a,b);
}


void    more_int(int nb, t_stack **a, t_stack **b)
{
    long long int small;

    small = -2147483648;
    if(nb > 2147483647)
        print_error(a,b);
    if (nb < small)
        print_error(a,b);
}

long long			ft_atoi_ps(const char *str,t_stack **a, t_stack **b)
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
        str++;
    }
    nb *= r;
    more_int(nb,a,b);
    return (nb);
}

void parse_command(t_stack **a, t_stack **b)
{
    char *line;

    while(get_next_line(0,line))
    {
        what_command(line,a,b);
        free(line);
    }
    if (!if_sorted(a,b))
        print_ko(a,b);
    else
        print_ok();
}


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *head;

    if (argc < 2)
        return (0);
    a = create_stack(head,argc,argv);
    if (a == NULL)
        return (0);
    parse_command(a,b);
    return (0);




}