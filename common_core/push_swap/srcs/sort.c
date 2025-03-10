#include "../includes/push_swap.h"

void    sort(t_list **a, t_list **b)
{
    int max;
    int max_bits;
    int i;
    int a_size;
    int j;
    int ops;

    max = find_max(*a);
    max_bits = count_bits(max);
    i = 0;
    ops = 0;
    while (i < max_bits)
    {
        a_size = ft_lstsize(*a);
        j = 0;
        while (j < a_size)
        {
            if ((*(int *)(*a)->content & (1 << i)) == 0)
            {
                push(a, b);
                ops++;
            }
            else
            {
                rotate(a);
                ops++;
            }
            j++;
        }
        while (*b)
        {
            push(b, a);
            ops++;
        }
        i++;
    }
    ft_printf("N. operations = %d\n", ops);
}