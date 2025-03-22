/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:56:56 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 20:57:12 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*lst_to_arr(t_list *lst, int size, int *is_error)
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

t_list *get_list_ranks(t_list *lst, int size, int *is_error)
{
	t_list	*ranks;
	int	*arr_sort;
	int	i;

	ranks = NULL;
	arr_sort = lst_to_arr(lst, size, is_error);
	if (*is_error == 1)
		return (NULL);
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
					ft_lstclear(&ranks, free);
					free(arr_sort);
					return (NULL);
				}
			}
			i++;
		}
		lst = lst->next;
	}
	free(arr_sort);
	return (ranks);
}

t_stack	*init_stack(t_list *lst, char id, int *is_error)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->list = lst;
	stack->size = ft_lstsize(lst);
	stack->rank = get_list_ranks(lst, stack->size, is_error);
	if (*is_error == 1)
	{
		return (NULL);
	}
	stack->id = id;
	return (stack);
}

void	free_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	if (!(*stack)->list)
		ft_lstclear(&(*stack)->list, free);
	if (!(*stack)->rank)
		ft_lstclear(&(*stack)->rank, free);
	free(*stack);
	*stack = NULL;
}

void	free_ab(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

void	error_ab(t_stack **a, t_stack **b)
{
	free_ab(a, b);
	ft_printf("Error\n");
	exit(1);
}