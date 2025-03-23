/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:19:05 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 21:13:17 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_four_slow(t_stack **a, t_stack **b, int len, int reverse)
{
	int	ref;

	if (is_sorted((*a)->rank, reverse, len))
		return ;
	if (reverse == 0)
		ref = find_min((*a)->rank, len);
	else
		ref = find_max((*a)->rank, len);
	if (*(int *)(*a)->rank->content != ref)
	{
		push(a, b);
		sort_three(a, len - 1, reverse);
		push(b, a);
		swap(a);
	}
	if (!is_sorted((*a)->rank, reverse, len))
	{
		push(a, b);
		sort_three(a, len - 1, reverse);
		push(b, a);
	}
}

static void	sort_four_fast(t_stack **a, t_stack **b, int len, int reverse)
{
	int	ref;

	if (is_sorted((*a)->rank, reverse, len))
		return ;
	if (reverse == 0)
		ref = find_min((*a)->rank, len);
	else
		ref = find_max((*a)->rank, len);
	if (*(int *)(*a)->rank->next->content == ref)
		rotate(a);
	if (*(int *)(*a)->rank->next->next->content == ref)
		rrotate(a);
	if (*(int *)(*a)->rank->next->next->next->content == ref)
		rrotate(a);
	if (*(int *)(*a)->rank->content == ref)
	{
		if (!is_sorted((*a)->rank, reverse, len))
		{
			push(a, b);
			sort_three(a, len - 1, reverse);
			push(b, a);
		}
	}
}

void	sort_four(t_stack **a, t_stack **b, int len, int reverse)
{
	if (len == 4)
	{
		if ((*a)->size > 4)
			sort_four_slow(a, b, len, reverse);
		else if ((*a)->size == 4)
			sort_four_fast(a, b, len, reverse);
	}
}
