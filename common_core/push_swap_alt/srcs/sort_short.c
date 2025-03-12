#include "../includes/push_swap.h"

static void    sort_two(t_list **lst)
{
    if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
        rotate(lst);
}

static void    sort_three(t_list **lst)
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

void    sort_short(t_list **lst)
{
    int lst_len;

    lst_len = ft_lstsize(*lst);
    if (lst_len == 3)
        sort_three(lst);
    else if (lst_len == 2)
        sort_two(lst);
}