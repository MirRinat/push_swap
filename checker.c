#include "push_swap.h"

void print_ok(t_stack **a, t_stack **b)
{
    ft_putstr("\33[32mOK\n");
    free_stack(a);
    free_stack(b);
    exit(1);
}

void print_ko(t_stack **a, t_stack **b)
{
    ft_putstr("\33[31mKO\n");
    free_stack(a);
	free_stack(b);
    exit(1);
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
    if (!ft_strcmp(str, "sa"))
        sa_nw(a);
    else if (!ft_strcmp(str, "sb"))
        sb_nw(b);
    else if (!ft_strcmp(str, "ss"))
        ss_nw(a, b);
    else if (!ft_strcmp(str, "pa"))
        pa_nw(a, b);
    else if (!ft_strcmp(str, "pb"))
        pb_nw(a, b);
    else if (!ft_strcmp(str, "ra"))
        ra_nw(a);
    else if (!ft_strcmp(str, "rb"))
        rb_nw(b);
    else if (!ft_strcmp(str, "rr"))
        rr_nw(a, b);
    else if (!ft_strcmp(str, "rra"))
        rra_nw(a);
    else if (!ft_strcmp(str, "rrb"))
        rrb_nw(b);
    else if (!ft_strcmp(str, "rrr"))
        rrr_nw(a, b);
    else
		print_error(a,b);
}


void    more_int(long long int nb, t_stack **a, t_stack **b)
{
    if(nb > 2147483647 || nb < -2147483648)
	{
		ft_putstr("\33[31mError\n");
		exit(1);
	}
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
        if (!ft_isdigit(*str))
        	print_error(a,b);
    }
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error(a,b);
		nb = nb * 10 + (*str - '0');
		more_int(nb * r,a,b);
		str++;
	}
    return (nb * r);
}

void check_duplicate(t_stack *a, t_stack *b, int nbr)
{
    int i;

    i = 0;
    while(a)
    {
        if(a->nb == nbr)
            i++;
        a = a->next;
    }
    if (i >= 2)
        print_error(&a,&b);
}

void parse_command(t_stack **a, t_stack **b)
{
    char *line;

    while(get_next_line(0,&line) > 0)
    {
        if (ft_strequ(line,""))
            break;
        what_command(line,a,b);
        free(line);
    }
    if (if_sorted(a,b))
		print_ok(a,b);
    else
		print_ko(a,b);
}
