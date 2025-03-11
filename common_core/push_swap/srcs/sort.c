#include "../includes/push_swap.h"

int is_sorted(t_list *lst)
{
    int num;

    num = *(int *)lst->content;
    while (lst->next)
    {
        if (num > *(int *)lst->next->content)
            return (0);
        lst = lst->next;
        num = *(int *)lst->content;
    }
    return (1);
}

void    sort_three(t_list **lst)
{
    int max;

    max = find_max(*lst);
    if (is_sorted(*lst))
        return ;
    if (*(int *)(*lst)->content == max)
    {
        rotate(lst);
        if (!is_sorted(*lst))
            swap(*lst);
    }
    else if (*(int *)(*lst)->next->content == max)
    {
        rrotate(lst);
        if (!is_sorted(*lst))
            swap(*lst);
    }
    else
        swap(*lst);
}

void    sort(t_list **a, t_list **b)
{
    int max_bits;
    int i;
    int a_size;
    int j;
    int n_pushes;

    max_bits = count_bits(find_max(*a));
    i = 0;
    while (i < max_bits)
    {
        n_pushes = 0;
        a_size = ft_lstsize(*a);
        j = 0;
        while (j < a_size)
        {
            if ((*(int *)(*a)->content & (1 << i)) == 0)
            {
                push(a, b);
                n_pushes++;
            }
            else
                rotate(a);
            j++;
        }
        while (n_pushes--)
            push(b, a);
        i++;
    }
    //ft_printf("N. operations = %d\n", ops);
}