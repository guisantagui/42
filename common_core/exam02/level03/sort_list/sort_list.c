#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;
	int	sorted;

	sorted = 0;
	tmp = lst;
	while (!sorted)
	{
		sorted = 1;
		while (lst->next != NULL)
		{
			if(((*cmp)(lst->data, lst->next->data) == 0)
			{
				swap = lst->data;
				lst->data = lst->next->data;
				lst->next->data = swap;
				lst = tmp;
				sorted = 0;
			}
			else
				lst = lst->next;
		}
		lst = tmp;
	}
	return (lst);
}
