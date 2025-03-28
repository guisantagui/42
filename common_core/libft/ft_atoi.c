/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:17:42 by gsantama          #+#    #+#             */
/*   Updated: 2024/11/29 15:17:46 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	res;
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
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (sign * res);
}
/*
int	main(int argc, char **argv)
{
	if(argc == 2)
	{
		printf("atoi: %d\n", atoi(argv[1]));
		printf("ft_atoi: %d\n", ft_atoi(argv[1]));
	}
	else
	{
		printf("\n");
	}
}
*/
