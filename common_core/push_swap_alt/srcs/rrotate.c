#include "../includes/push_swap.h"

void    rrotate(t_list **lst)
{
    t_list *first;
    t_list	*last;
    t_list  *sec_last;

    first = *lst;
    last = *lst;
	while (last -> next)
    {
        sec_last = last;
		last = last -> next;
    }
    last->next = first;
    *lst = last;
    sec_last->next = NULL;
}