#include "../includes/push_swap.h"

void    subs_val(t_list **lst, int min)
{
    t_list *head;
    int *content;
    unsigned int    *shift_content;

    head = *lst;
    while (head)
    {
        content = (int *)head->content;
        shift_content = malloc(sizeof(unsigned int));
        if (!shift_content)
        {
            ft_printf("Error\n");
            return;
        }
        *shift_content = (unsigned int)(*content - min);
        free(head->content);
        head->content = shift_content;
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