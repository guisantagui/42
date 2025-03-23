/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:02:30 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 21:04:24 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
			i++;
		if (str[i] == '+' || str[i] == '-')
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
	while (!arr[i])
	{
		free(arr[i]);
		i++;
	}
}

int	atoi_cust(const char *str, int *is_error)
{
	int	i;
	long	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] && ft_isdigit(str[i])) && *is_error == 0)
	{
		if (res > (INT_MAX / 10) || (res == INT_MAX / 10 && (str[i] - '0') > (INT_MAX % 10)))
		{
			*is_error = 1;
			return (0);
		}
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return ((int)(sign * res));
}

void	error(t_list **lst)
{
	if (lst != NULL || *lst != NULL)
		ft_lstclear(lst, free);
	ft_printf("Error\n");
	exit(1);
}