/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:16:30 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 19:18:52 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted_asc(t_list *lst, int len)
{
	int	num;
	int	i;

	if (ft_lstsize(lst) == 1)
		return (1);
	num = *(int *)lst->content;
	i = 1;
	while (lst->next && i < len)
	{
		if (num > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
		num = *(int *)lst->content;
		i++;
	}
	return (1);
}

static int	is_sorted_desc(t_list *lst, int len)
{
	int	num;
	int	i;

	if (ft_lstsize(lst) == 1)
		return (1);
	num = *(int *)lst->content;
	i = 1;
	while (lst->next && i < len)
	{
		if (num < *(int *)lst->next->content)
			return (0);
		lst = lst->next;
		num = *(int *)lst->content;
		i++;
	}
	return (1);
}

int	is_sorted(t_list *lst, int reverse, int len)
{
	if (reverse == 1)
		return (is_sorted_desc(lst, len));
	else
		return (is_sorted_asc(lst, len));
}
