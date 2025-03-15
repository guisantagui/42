#include "../includes/push_swap.h"

void    rotate(t_list **lst)
{
    t_list *first;
    t_list	*last;

    first = *lst;
    last = *lst;
	while (last -> next != NULL)
		last = last -> next;
    *lst = first->next;
    first->next = NULL;
    last->next = first;
    ft_printf("rotate\n");
}