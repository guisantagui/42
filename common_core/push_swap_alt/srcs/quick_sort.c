/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:41:05 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 20:54:19 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	bubblesort(int *arr, int len)
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

static int	get_pivot(t_list *lst, int len)
{
	int		*values;
	t_list	*current;
	int		i;
	int		pivot;

	values = malloc(sizeof(int) * len);
	current = lst;
	i = 0;
	while (i < len && current)
	{
		values[i] = *(int *)current->content;
		current = current->next;
		i++;
	}
	bubblesort(values, len);
	pivot = values[len / 2];
	free(values);
	return (pivot);
}

static t_stack_state	init_state(t_stack **stack, int len)
{
	t_stack_state	state;

	state.pivot = get_pivot((*stack)->list, len);
	state.content_less = 0;
	state.first_content_set = 0;
	state.n_rotations = 0;
	return (state);
}

static t_stack_state	do_partition(t_stack **a, t_stack **b, int len,
		int reverse)
{
    t_stack_state	state;

    state = init_state(a, len);
	while (len > 0)
	{
		if ((!reverse && (*(int *)(*a)->list->content < state.pivot)) ||
			(reverse && (*(int *)(*a)->list->content > state.pivot)))
		{
			push(a, b);
			state.content_less++;
		}
		else
		{
			if (!state.first_content_set)
			{
				state.first_content = *(int *)(*a)->list->content;
				state.first_content_set = 1;
			}
			rotate(a);
		}
		len--;
	}
    return (state);
}

void	quick_sort(t_stack **a, t_stack **b, int len, int reverse)
{
	t_stack_state	state;

	if (len <= 5)
	{
		sort_short(a, b, len, reverse);
		return ;
	}
	state = do_partition(a, b, len, reverse);
	state.n_rotations = len - state.content_less;
	if (*(int *)(*a)->list->content != state.first_content)
	{
		while (state.n_rotations > 0)
		{
			rrotate(a);
			state.n_rotations--;
		}
	}
	quick_sort(b, a, state.content_less, !reverse);
	quick_sort(a, b, len - state.content_less, reverse);
	while (state.content_less > 0)
	{
		push(b, a);
		state.content_less--;
	}
}
