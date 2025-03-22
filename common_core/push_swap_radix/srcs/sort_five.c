/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:28:58 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 21:12:25 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_five_slow(t_stack **a, t_stack **b, int len, int reverse)
{
	int	ref;

	if (is_sorted((*a)->list, reverse, len))
		return ;
	if (!reverse)
		ref = find_min((*a)->list, len);
	else
		ref = find_max((*a)->list, len);
	if (*(int *)(*a)->list->content != ref)
	{
		push(a, b);
		sort_four(a, b, len - 1, reverse);
		push(b, a);
		swap(a);
	}
	if (!is_sorted((*a)->list, reverse, len))
	{
		push(a, b);
		sort_four(a, b, len - 1, reverse);
		push(b, a);
	}
}

static void	sort_five_fast(t_stack **a, t_stack **b, int len, int reverse)
{
	int	ref;

	if (is_sorted((*a)->list, reverse, len))
		return ;
	if (reverse == 0)
		ref = find_min((*a)->list, len);
	else
		ref = find_max((*a)->list, len);
	if (*(int *)(*a)->list->next->next->content == ref)
		rotate(a);
	if (*(int *)(*a)->list->next->content == ref)
		rotate(a);
	if (*(int *)(*a)->list->next->next->next->content == ref)
		rrotate(a);
	if (*(int *)(*a)->list->next->next->next->next->content == ref)
		rrotate(a);
	if (!is_sorted((*a)->list, reverse, len))
	{
		push(a, b);
		sort_four(a, b, len - 1, reverse);
		push(b, a);
	}
}

void	sort_five(t_stack **a, t_stack **b, int len, int reverse)
{
	if (len == 5)
	{
		if ((*a)->size > 5)
			sort_five_slow(a, b, len, reverse);
		else if ((*a)->size == 5)
			sort_five_fast(a, b, len, reverse);
	}
}
