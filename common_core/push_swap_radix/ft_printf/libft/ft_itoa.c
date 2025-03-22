/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:19:26 by gsantama          #+#    #+#             */
/*   Updated: 2024/11/29 18:09:37 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

static int	get_num_digits(long n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		digits += 1;
		n /= 10;
	}
	return (digits);
}

static void	fill_string(char *str, long num, int digs, int pos)
{
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[digs] = '\0';
	while ((digs - 1) >= pos)
	{
		str[digs - 1] = (num % 10) + '0';
		num /= 10;
		digs--;
	}
}

char	*ft_itoa(int n)
{
	int		digs;
	int		i;
	char	*str;
	long	num;

	digs = get_num_digits(n);
	i = 0;
	num = n;
	if (num < 0)
	{
		digs += 1;
		i++;
	}
	str = (char *)malloc((digs + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fill_string(str, num, digs, i);
	return (str);
}
/*
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        printf("%s\n", ft_itoa(atoi(argv[1])));
        printf("%s\n", ft_itoa(-2147483648));
    }
}
*/
