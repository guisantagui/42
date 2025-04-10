#include "../includes/push_swap.h"

int find_min(t_list *lst)
{
    int min;

    min = *(int *)lst->content;
    lst = lst->next;
    while (lst)
    {
        if (*(int *)lst->content < min)
            min = *(int *)lst->content;
        lst = lst->next;
    }
    return (min);
}

int find_max(t_list *lst)
{
    int max;

    max = *(int *)lst->content;
    lst = lst->next;
    while (lst)
    {
        if (*(int *)lst->content > max)
            max = *(int *)lst->content;
        lst = lst->next;
    }
    return (max);
}