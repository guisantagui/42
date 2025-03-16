#include "../includes/push_swap.h"

void    push(t_stack **src, t_stack **dst)
{
    t_list  *first;

    if (!src || !*src || !(*src)->list)
        return;
    first = (*src)->list;
    (*src)->list = first->next;
    first->next = NULL;
    ft_lstadd_front(&(*dst)->list, first);
    (*src)->size--;
    (*dst)->size++; 
    ft_printf("p%c\n", (*dst)->id);
}

void    swap(t_stack **stack)
{
    void    *t;

    if ((*stack)->list && (*stack)->list->next)
    {
        t = (*stack)->list->content;
        (*stack)->list->content = (*stack)->list->next->content;
        (*stack)->list->next->content = t;
        ft_printf("s%c\n", (*stack)->id);
    }
}

void    rotate(t_stack **stack)
{
    t_list *first;
    t_list	*last;

    if ((*stack)->size > 1)
    {
        first = (*stack)->list;
        last = (*stack)->list;
	    while (last -> next != NULL)
	    	last = last -> next;
        (*stack)->list = first->next;
        first->next = NULL;
        last->next = first;
        ft_printf("r%c\n", (*stack)->id);
    }
}

void    rrotate(t_stack **stack)
{
    t_list *first;
    t_list	*last;
    t_list  *sec_last;

    if ((*stack)->size > 1)
    {
        first = (*stack)->list;
        last = (*stack)->list;
	    while (last -> next)
        {
            sec_last = last;
	    	last = last -> next;
        }
        last->next = first;
        (*stack)->list = last;
        sec_last->next = NULL;
        ft_printf("rr%c\n", (*stack)->id);
    }
}