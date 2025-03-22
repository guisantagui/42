/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:13:39 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 19:16:15 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_dups(t_list *lst)
{
	t_list	*lst_next;

	while (lst && lst->next)
	{
		lst_next = lst->next;
		while (lst_next)
		{
			if (*(int *)lst->content == *(int *)lst_next->content)
				return (1);
			lst_next = lst_next->next;
		}
		lst = lst->next;
	}
	return (0);
}
