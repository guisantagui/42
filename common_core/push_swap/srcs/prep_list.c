#include "../includes/push_swap.h"

void    subs_val(t_list **lst, int min)
{
    t_list *head;

    head = *lst;
    while (head)
    {
        *(int *)(head->content) -= min;
        head = head->next;
    }
}

void    add_val(t_list **lst, int min)
{
    t_list *head;

    head = *lst;
    while (head)
    {
        *(int *)(head->content) += min;
        head = head->next;
    }
}