/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:10:30 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 19:13:15 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_list *lst, int len)
{
	int	min;
	int	i;

	min = *(int *)lst->content;
	lst = lst->next;
	i = 1;
	while (lst && i < len)
	{
		if (*(int *)lst->content < min)
			min = *(int *)lst->content;
		lst = lst->next;
		i++;
	}
	return (min);
}

int	find_max(t_list *lst, int len)
{
	int	max;
	int	i;

	max = *(int *)lst->content;
	lst = lst->next;
	i = 1;
	while (lst && i < len)
	{
		if (*(int *)lst->content > max)
			max = *(int *)lst->content;
		lst = lst->next;
		i++;
	}
	return (max);
}

/*
int find_min(t_list *lst)
{
    int min;

    min = *(int *)lst->content;
    lst = lst->next;
    while (lst)
    {
        if (*(int *)lst->content < min)
            min = *(int *)lst->content;
        lst = lst->next;
    }
    return (min);
}

int find_max(t_list *lst)
{
    int max;

    max = *(int *)lst->content;
    lst = lst->next;
    while (lst)
    {
        if (*(int *)lst->content > max)
            max = *(int *)lst->content;
        lst = lst->next;
    }
    return (max);
}
*/
