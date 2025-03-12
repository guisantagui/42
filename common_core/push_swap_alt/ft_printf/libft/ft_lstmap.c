/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:20:28 by gsantama          #+#    #+#             */
/*   Updated: 2024/11/29 15:38:15 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;
	t_list	*lst_head;

	if (!lst || !f || !del)
		return (NULL);
	lst_map = ft_lstnew(f(lst->content));
	if (!lst_map)
		return (NULL);
	lst_head = lst_map;
	lst = lst->next;
	while (lst)
	{
		lst_map->next = ft_lstnew(f(lst->content));
		if (!lst_map->next)
		{
			ft_lstclear(&lst_head, del);
			return (NULL);
		}
		lst_map = lst_map->next;
		lst = lst->next;
	}
	lst_map->next = NULL;
	return (lst_head);
}
