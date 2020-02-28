#include <stdio.h>
#include "push_swap.h"






t_stack *sort(t_stack *a, t_stack *b, int count_a)
{
    if (if_sorted(&a, &b))
        return(NULL);
    if (count_a == 2)
        sort_two(&a);
    else if (count_a == 3)
        sort_three(&a);
    else if (count_a >= 4 && count_a < 7)
        sort_five(&a,&b);
    else if (count_a >= 7 && count_a < 50)
        insert_sort(&a,&b);
    else
        sorting(&a,&b,count_a);
    return (a);
}



int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int count_a;
    t_stack *head;

    if (argc > 2)
        a = create_stack(&head,argv,argc);
    else
        return (0);
//    print_list(a);
//    print_list(b);
    count_a = lst_count(&a);
	a = sort(a,b,count_a);
	free_stack(&a);
	free_stack(&b);
    return (0);
}
