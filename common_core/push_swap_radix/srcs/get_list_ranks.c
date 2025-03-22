#include "../includes/push_swap.h"

static int	*lst_to_arr(t_list *lst, int size, int *is_error)
{
	int		*values;
	int	i;

	values = malloc(sizeof(int) * size);
	if (!values)
	{
		*is_error = 1;
		return (0);
	}
	i = 0;
	while (i < size && lst)
	{
		values[i] = *(int *)lst->content;
		lst = lst->next;
		i++;
	}
	bubblesort(values, size);
	return (values);
}

static void	num_to_node(int n, t_list **lst, int *is_error)
{
	int		*num;
	t_list	*node;

	num = malloc(sizeof(int));
	if (!num)
	{
		*is_error = 1;
		return ;
	}
	*num = n;
	node = ft_lstnew(num);
	if (!node || *is_error == 1)
	{
		*is_error = 1;
		free(num);
		return ;
	}
	ft_lstadd_back(lst, node);
}

static void	free_aux(t_list **ranks, int *arr_sort)
{
	ft_lstclear(ranks, free);
	free(arr_sort);
}

static t_list *map_ranks(t_list *lst, int size, int *arr_sort, int *is_error)
{
	t_list	*ranks;
	int	i;

	ranks = NULL;
	while (lst)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)lst->content == arr_sort[i])
			{
				num_to_node(i, &ranks, is_error);
				if (*is_error == 1)
				{
					free_aux(&ranks, arr_sort);
					return (NULL);
				}
			}
			i++;
		}
		lst = lst->next;
	}
	return (ranks);
}

t_list *get_list_ranks(t_list *lst, int size, int *is_error)
{
	t_list	*ranks;
	int	*arr_sort;

	ranks = NULL;
	arr_sort = lst_to_arr(lst, size, is_error);
	if (*is_error == 1)
		return (NULL);

	ranks = map_ranks(lst, size, arr_sort, is_error);
    if (*is_error == 0)
        free(arr_sort);
	return (ranks);
}
