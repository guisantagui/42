/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:25:51 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 20:37:40 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_short(t_stack **a, t_stack **b, int len, int reverse)
{
	if (len == 2)
		sort_two(a, len, reverse);
	else if (len == 3)
		sort_three(a, len, reverse);
	else if (len == 4)
		sort_four(a, b, len, reverse);
	else if (len == 5)
		sort_five(a, b, len, reverse);
}
