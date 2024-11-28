#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *end;

    if (!*lst)
    {
        *lst = new;
        return ;
    }
    end = *lst;
    while (end -> next != NULL)
        end = end -> next;
    end -> next = new;
}