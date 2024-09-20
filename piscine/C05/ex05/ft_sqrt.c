/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:51:50 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/20 17:59:54 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0 || nb > 2147395600)
		return (0);
	else
	{
		i = 0;
		while (i * i <= nb)
		{
			if (i * i == nb)
				return (i);
			else
				i++;
		}
		return (0);
	}
}
/*
int	main()
{
	int	num = 26;
	int     num1 = 25;
	int     num2 = 16;
	int     num3 = 100;
	int	num4 = -4;
	int	num5 = 2147483647;
	int	num6 = 2147395599;
	int     num7 = 3;
	int	num8 = 9;
	int     num9 = 0;
	int     num10 = 1000000;
	int     num11 = -2147483648;
	printf ("sqrt(%d) = %d\n", num, ft_sqrt(num));
	printf ("sqrt(%d) = %d\n", num1, ft_sqrt(num1));
	printf ("sqrt(%d) = %d\n", num2, ft_sqrt(num2));
	printf ("sqrt(%d) = %d\n", num3, ft_sqrt(num3));
	printf ("sqrt(%d) = %d\n", num4, ft_sqrt(num4));
	printf ("sqrt(%d) = %d\n", num5, ft_sqrt(num5));
	printf ("sqrt(%d) = %d\n", num6, ft_sqrt(num6));
	printf ("sqrt(%d) = %d\n", num7, ft_sqrt(num7));
	printf ("sqrt(%d) = %d\n", num8, ft_sqrt(num8));
	printf ("sqrt(%d) = %d\n", num9, ft_sqrt(num9));
	printf ("sqrt(%d) = %d\n", num10, ft_sqrt(num10));
	printf ("sqrt(%d) = %d\n", num11, ft_sqrt(num11));
}
*/
