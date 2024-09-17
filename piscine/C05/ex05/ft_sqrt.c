/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:26:19 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/17 22:27:07 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	sqrt_help(int nb, int g)
{
	if (nb < 0 || nb > 2147395600)
		return (0);
	else if (nb == 0 || nb == 1)
		return (nb);
	if (g * g == nb)
		return (g);
	else if (g * g < nb && (g + 1) * (g + 1) > nb)
		return (0);
	else
		return (sqrt_help(nb, (g + nb / g) / 2));
}

int	ft_sqrt(int nb)
{
	int	g;

	g = nb / 2;
	return (sqrt_help(nb, g));
}
/*
int	main()
{
	int	num = 26;
	int     num1 = 25;
	int     num2 = 16;
	int     num3 = 100;
	printf ("sqrt(%d) = %d\n", num, ft_sqrt(num));
	printf ("sqrt(%d) = %d\n", num1, ft_sqrt(num1));
	printf ("sqrt(%d) = %d\n", num2, ft_sqrt(num2));
	printf ("sqrt(%d) = %d\n", num3, ft_sqrt(num3));
}
*/
