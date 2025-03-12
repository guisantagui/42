#include "../includes/push_swap.h"

void    swap(t_list *lst)
{
    void    *t;

    if (lst && lst->next)
    {
        t = lst->content;
        lst->content = lst->next->content;
        lst->next->content = t;
    }
}