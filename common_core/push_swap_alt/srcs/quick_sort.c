#include "../includes/push_swap.h"

static int get_pivot(t_list *lst, int len)
{
    int min;
    int max;

    min = find_min(lst);
    max = find_max(lst);
    return ((max - min) / 2);
}

void quick_sort(t_list **a, t_list **b, int len)
{
    // Base case for small arrays
    if (len <= 3) {
        sort_small(a, b, len);
        return;
    }
    
    // Choose pivot (can use various strategies)
    int pivot = get_pivot(*a, len);
    int elements_less = 0;
    int initial_len = len;
    
    // Partition phase
    while (len > 0) {
        if (*(int*)(*a)->content < pivot) {
            push(a, b);
            elements_less++;
        } else {
            rotate(a);
        }
        len--;
    }
    
    // Restore elements greater than pivot to stack A
    int elements_greater = initial_len - elements_less;
    while (elements_greater > 0) {
        rrotate(a);
        elements_greater--;
    }
    
    // Recursively sort both partitions
    quick_sort(b, a, elements_less);     // Sort smaller elements (now in B)
    quick_sort(a, b, initial_len - elements_less);  // Sort larger elements (in A)
    
    // Merge the sorted partitions
    while (elements_less > 0) {
        push(b, a);
        elements_less--;
    }
}