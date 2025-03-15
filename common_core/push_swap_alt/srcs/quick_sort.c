#include "../includes/push_swap.h"

static int get_pivot(t_list *lst, int len)
{
    // Create an array to hold values
    int *values = malloc(sizeof(int) * len);
    t_list *current = lst;
    
    // Copy values to the array
    for (int i = 0; i < len && current; i++) {
        values[i] = *(int*)current->content;
        current = current->next;
    }
    
    // Simple sort for the array (bubble sort is fine for our purposes)
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    
    // Get median value
    int pivot = values[len / 2];
    free(values);
    return pivot;
}

void quick_sort(t_list **a, t_list **b, int len, int reverse)
{
    // Base case for small arrays
    if (len <= 4) {
        sort_short(a, b, len, reverse);
        return;
    }
    
    // Choose pivot (can use various strategies)
    int pivot = get_pivot(*a, len);
    int first_element = *(int*)(*a)->content;
    //ft_printf("Len: %d\n", len);
    //ft_printf("Reverse: %d\n", reverse);
    //ft_printf("Pivot: %d\n", pivot);
    //ft_printf("First element: %d\n", first_element);
    int elements_less = 0;
    int initial_len = len;
    
    //ft_printf("A before partition\n");
    //print_list(*a);
    //ft_printf("B before partition\n");
    //print_list(*b);
    // Partition phase
    while (len > 0) {
        if ((!reverse && (*(int*)(*a)->content < pivot)) || 
            (reverse && (*(int*)(*a)->content > pivot))) {
            push(a, b);
            elements_less++;
        } else {
            rotate(a);
        }
        len--;
    }
    //ft_printf("First element A after partition: %d\n", *(int*)(*a)->content);
    //print_list(*a);
    //ft_printf("First element B after partition: %d\n", *(int*)(*b)->content);
    //print_list(*b);

    // Restore elements greater than pivot to stack A
    int elements_greater = initial_len - elements_less;
    if (*(int*)(*a)->content != first_element)
    {
        while (elements_greater > 0) {
            rrotate(a);
            elements_greater--;
        }
    }
    //ft_printf("A after restoration:\n");
    //print_list(*a);
    //ft_printf("B after restoration:\n");
    //print_list(*b);
    //ft_printf("Len A: %d\n", initial_len - elements_less);
    //ft_printf("Len B: %d\n", elements_less);
    // Recursively sort both partitions
    quick_sort(b, a, elements_less, !reverse);     // Sort smaller elements (now in B)
    quick_sort(a, b, initial_len - elements_less, reverse);  // Sort larger elements (in A)
    
    // Merge the sorted partitions
    while (elements_less > 0) {
        push(b, a);
        elements_less--;
    }
}