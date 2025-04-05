/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:41:05 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/05 15:32:24 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubblesort(int *arr, int len)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}

int	get_pivot(t_list *lst, int len, int *is_error)
{
	int		*values;
	int		i;
	int		pivot;

	values = malloc(sizeof(int) * len);
	if (!values)
	{
		*is_error = 1;
		return (0);
	}
	i = 0;
	while (i < len && lst)
	{
		values[i] = *(int *)lst->content;
		lst = lst->next;
		i++;
	}
	bubblesort(values, len);
	pivot = values[len / 2];
	free(values);
	return (pivot);
}

t_stack_state	init_state(t_stack **a, t_stack **b, int len)
{
	t_stack_state	state;

	state.error = 0;
	state.pivot = get_pivot((*a)->rank, len, &state.error);
	state.content_less = 0;
	state.first_content_set = 0;
	state.n_rotations = 0;
	if (state.error == 1)
		error_ab(a, b);
	return (state);
}

t_stack_state	do_partition(t_stack **a, t_stack **b, int len,
		int reverse)
{
	t_stack_state	state;

	state = init_state(a, b, len);
	while (len > 0)
	{
		if ((!reverse && (*(int *)(*a)->rank->content < state.pivot)) ||
			(reverse && (*(int *)(*a)->rank->content > state.pivot)))
		{
			push(a, b);
			state.content_less++;
		}
		else
		{
			if (!state.first_content_set)
			{
				state.first_content = *(int *)(*a)->rank->content;
				state.first_content_set = 1;
			}
			rotate(a);
		}
		len--;
	}
	return (state);
}

void	reset_stacks(t_stack **a, t_stack **b, t_stack_state state)
{
	while (state.content_less > 0)
	{
		push(b, a);
		state.content_less--;
	}
}
