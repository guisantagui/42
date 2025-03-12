#include "../includes/push_swap.h"

int find_min(t_list *lst, int len)
{
    int min;
    int i;

    min = *(int *)lst->content;
    lst = lst->next;
    i = 1;
    while (lst && i < len)
    {
        if (*(int *)lst->content < min)
            min = *(int *)lst->content;
        lst = lst->next;
        i++;
    }
    return (min);
}

int find_max(t_list *lst, int len)
{
    int max;
    int i;

    max = *(int *)lst->content;
    lst = lst->next;
    i = 1;
    while (lst && i < len)
    {
        if (*(int *)lst->content > max)
            max = *(int *)lst->content;
        lst = lst->next;
        i++;
    }
    return (max);
}