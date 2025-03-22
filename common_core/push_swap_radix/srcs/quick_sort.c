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

static int	loc_num(t_list *lst, int num)
{
	int	i;

	i = 0;
	while (lst && *(int *)lst->content != num)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static void	reset_rotations(t_stack **stack, t_stack_state state)
{
	int	num_idx;

	if (*(int *)(*stack)->rank->content != state.first_content)
	{
		num_idx = loc_num((*stack)->rank, state.first_content);
		while (*(int *)(*stack)->rank->content != state.first_content)
		{
			if (num_idx < (*stack)->size / 2)
				rotate(stack);
			else
				rrotate(stack);
		}
	}
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
	reset_rotations(a, state);
	quick_sort(b, a, state.content_less, !reverse);
	quick_sort(a, b, len - state.content_less, reverse);
	reset_stacks(a, b, state);
}
