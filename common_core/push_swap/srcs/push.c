#include "../includes/push_swap.h"

void    push(t_list **src, t_list **dst)
{
    t_list  *first;

    first = *src;
    *src = first->next;
    first->next = NULL;
    ft_lstadd_front(dst, first);
}