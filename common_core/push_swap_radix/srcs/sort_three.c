/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:09:39 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 21:14:07 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_slow(t_stack **stack, int len, int reverse)
{
	int	ref;

	if (is_sorted((*stack)->rank, reverse, len))
		return ;
	if (reverse == 0)
		ref = find_max((*stack)->rank, len);
	else
		ref = find_min((*stack)->rank, len);
	if (*(int *)(*stack)->rank->content == ref)
	{
		swap(stack);
		rotate(stack);
		swap(stack);
		rrotate(stack);
	}
	else if (*(int *)(*stack)->rank->next->content == ref)
	{
		rotate(stack);
		swap(stack);
		rrotate(stack);
	}
	sort_two(stack, len, reverse);
}

static void	sort_three_fast(t_stack **stack, int len, int reverse)
{
	int	ref;

	if (is_sorted((*stack)->rank, reverse, len))
		return ;
	if (reverse == 0)
		ref = find_max((*stack)->rank, len);
	else
		ref = find_min((*stack)->rank, len);
	if (*(int *)(*stack)->rank->content == ref)
	{
		rotate(stack);
		if (!is_sorted((*stack)->rank, reverse, len))
			swap(stack);
	}
	else if (*(int *)(*stack)->rank->next->content == ref)
	{
		rrotate(stack);
		if (!is_sorted((*stack)->rank, reverse, len))
			swap(stack);
	}
	else
		swap(stack);
}

void	sort_three(t_stack **stack, int len, int reverse)
{
	if (len == 3)
	{
		if ((*stack)->size > 3)
			sort_three_slow(stack, len, reverse);
		else if ((*stack)->size == 3)
			sort_three_fast(stack, len, reverse);
	}
}
