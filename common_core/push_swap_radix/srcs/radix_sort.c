#include "../includes/push_swap.h"

static int count_bits(int n)
{
    int bits;
    if (n == 0)
        return (1);

    bits = 0;
    while (n > 0) {
        bits++;
        n >>= 1;
    }
    return (bits);
}


static void	sort_b(t_stack **a, t_stack **b, int max_bits, int bit)
{
	int	size;

	size = (*b)->size;
	while (size-- && bit <= max_bits && !is_sorted((*a)->rank, 0, (*a)->size))
	{
		if ((*(int *)(*b)->rank->content & (1 << bit)) == 0)
			rotate(b);
		else
			push(b, a);
	}
	if (is_sorted((*a)->rank, 0, (*a)->size))
    {
		while ((*b)->size != 0)
			push(b, a);
    }
}

void    radix_sort(t_stack **a, t_stack **b)
{
    int max_bits;
    int bit;
    int a_size;
    int j;

    max_bits = count_bits(find_max((*a)->rank, (*a)->size));
    bit = 0;
    while (bit < max_bits)
    {
        a_size = (*a)->size;
        j = 0;
        while (j < a_size && !is_sorted((*a)->rank, 0, (*a)->size))
        {
            if ((*(int *)(*a)->rank->content & (1 << bit)) == 0)
                push(a, b);
            else
                rotate(a);
            j++;
        }
        bit++;
        sort_b(a, b, max_bits, bit);
    }
    while ((*b)->size != 0)
        push(b, a);
}