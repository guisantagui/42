#include "../includes/push_swap.h"

void    error(t_list **lst)
{
    ft_lstclear(lst, free);
	ft_printf("Error\n");
	exit(1);
}