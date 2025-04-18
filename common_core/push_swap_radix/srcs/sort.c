/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:41:05 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/05 15:39:28 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_data **data, char *alg)
{
	if (!is_sorted((*data)->a->list, 0, (*data)->a->size))
	{
		if (ft_strncmp(alg, "QS", 2) == 0)
			quick_sort(&(*data)->a, &(*data)->b, (*data)->a->size, 0);
		else if (ft_strncmp(alg, "RS", 2) == 0)
			radix_sort(&(*data)->a, &(*data)->b);
	}
}
