#include "../includes/push_swap.h"

void    sort(t_list **a, t_list **b)
{
    int max;
    int max_bits;
    int i;
    int a_size;
    int j;
    //int top_val;

    max = find_max(*a);
    max_bits = count_bits(max);
    ft_printf("max_bits: %d\n", max_bits);
    i = 0;
    a_size = ft_lstsize(*a);
    j = 0;
    while (i < max_bits)
    {
        ft_printf("Jaja");
        while (j < a_size)
        {
            ft_printf("Jeje");
            //top_val = (*a)->content;
            if ((*(int *)(*a)->content & (1 << i)) == 0)
            {
                ft_printf("Jiji");
                push(a, b);
            }
            else
                rotate(a);
            j++;
        }
        while (*b)
            push(b, a);
        i++;
    }
}