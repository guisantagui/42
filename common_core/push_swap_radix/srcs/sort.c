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

void    sort(t_stack **a, t_stack **b, char *alg)
{
    if (!is_sorted((*a)->list, 0, (*a)->size))
    {
        if (ft_strncmp(alg, "QS", 2) == 0)
            quick_sort(a, b, (*a)->size, 0);
        else if (ft_strncmp(alg, "RS", 2) == 0)
            radix_sort(a, b);
    }
}