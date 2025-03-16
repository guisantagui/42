#include "../includes/push_swap.h"

void    push(t_list **src, t_list **dst)
{
    t_list  *first;

    if (!src || !*src)
        return;
    first = *src;
    *src = first->next;
    first->next = NULL;
    ft_lstadd_front(dst, first);
    ft_printf("push\n");
}

void    swap(t_list *lst)
{
    void    *t;

    if (lst && lst->next)
    {
        t = lst->content;
        lst->content = lst->next->content;
        lst->next->content = t;
    }
    ft_printf("swap\n");
}

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
    ft_printf("rrotate\n");
}