#include "push_swap.h"

void print_ok(t_stack **a, t_stack **b)
{
    ft_putstr("\33[32mOK\n");
	if (*a)
		free_stack(a);
    if (*b)
    	free_stack(b);
    exit(1);
}

void print_ko(t_stack **a, t_stack **b)
{
    ft_putstr("\33[32mKO\n");
	if (*a)
		free_stack(a);
    if (*b)
    	free_stack(b);
    exit(1);
}

void		print_error(t_stack **a, t_stack **b)
{
    ft_putstr("\33[31mError\033[0m\n");
	if (*a)
    	free_stack(a);
    if (*b && b)
    	free_stack(b);
    exit(1);
}

int			is_space(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (1);
    return (0);
}

void		what_command(char *str, t_stack **a, t_stack **b)
{
    if (ft_strcmp(str, "sa") == 0)
        sa_nw(a);
    else if (ft_strequ(str, "sb"))
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
//    else if (ft_strequ(str, ""))
//        return ;
    else
		print_error(a,b);
}


void    more_int(long long int nb, t_stack **a, t_stack **b)
{
    long long int small;

    if(nb > 2147483647)
	{
		ft_putstr("\33[31mError\033[0m\n");
		exit(1);
	}
    if (nb < -2147483648)
	{
		ft_putstr("\33[31mError\033[0m\n");
		exit(1);
	}
}

long long			ft_atoi_ps(const char *str,t_stack **a, t_stack **b)
{
    long long	r;
	long long	nb;

    r = 1;
    nb = 0;
    while (is_space(*str))
        str++;
    if (*str == '-' || *str == '+')
	{
        if (*str == '-')
            r = -1;
        if (!ft_isdigit(*str + 1))
        	print_error(a,b);
        str++;
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



int parse_command(t_stack **a, t_stack **b)
{
    char *line;

//    if (if_sorted(a,b))
//        print_ok(a,b);
    while(get_next_line(0,&line) > 0)
    {
//    	if (if_sorted(a,b))
//    		print_ok(a,b);
//        if (ft_strequ(line,""))
//            break;
//        if (if_sorted(a,b))
//    		print_ok(a,b);
        what_command(line,a,b);
//        if (if_sorted(a,b))
//            print_ok(a,b);
        free(line);
    }
//    print_list(*a);
//    printf("\n");
//    print_list(*b);
//	if (*b)
//        print_ko(a,b);
//    if (if_sorted(a,b))
    if (if_sorted(a,b))
		ft_putstr("OK\n");
//        print_ok(a,b);
    else
		ft_putstr("\033[31mKO\033[0m\n");
//        print_ko(a,b);
    return (0);
}
