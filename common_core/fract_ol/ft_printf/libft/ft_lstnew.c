/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:20:37 by gsantama          #+#    #+#             */
/*   Updated: 2024/11/29 15:20:38 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nu;

	nu = malloc(sizeof(t_list));
	if (!nu)
		return (NULL);
	nu -> content = content;
	nu -> next = NULL;
	return (nu);
}
