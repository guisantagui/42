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