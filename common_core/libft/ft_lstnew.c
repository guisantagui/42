#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nu;

	nu = malloc(sizeof(t_list));
	if (!nu)
		return (NULL);
	nu -> content = content;
	nu -> next = NULL;
	return (nu);
}