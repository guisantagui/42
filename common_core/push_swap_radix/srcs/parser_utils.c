/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:02:30 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/08 20:02:38 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(char *str)
{
	int	i;
	int	nums_start;

	i = 0;
	nums_start = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v') && nums_start == 0)
			i++;
		if (ft_isdigit(str[i]))
			nums_start = 1;
		if ((str[i] == '+' || str[i] == '-') && nums_start == 0)
			i++;
		if (str[i] == '\0')
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error(t_list **lst)
{
	if (lst != NULL || *lst != NULL)
		ft_lstclear(lst, free);
	write(2, "Error\n", 6);
	exit(1);
}
