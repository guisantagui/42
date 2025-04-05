/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_cust.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:23:58 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/05 15:28:05 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	skip_spaces(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
	{
		i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				*sign *= -1;
			i++;
		}
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
	}
	return (i);
}

int	atoi_cust(const char *str, int *is_error)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = skip_spaces(str, &sign);
	while ((str[i] && ft_isdigit(str[i])) && *is_error == 0)
	{
		if (res > (INT_MAX / 10)
			|| (res == INT_MAX / 10 && (str[i] - '0') > (INT_MAX % 10)))
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
