#include "../includes/push_swap.h"

int count_bits(int n)
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