#include "../includes/push_swap.h"

int	has_dups(t_list *lst)
{
	t_list  *lst_next;

	while (lst && lst->next)
	{
		lst_next = lst->next;
		while (lst_next)
		{
			if (lst->content == lst_next->content)
				return (1);
			lst_next = lst_next->next;
		}
		lst = lst->next;
	}
	return (0);
}
