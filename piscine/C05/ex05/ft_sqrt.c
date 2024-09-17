/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:38:15 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/17 19:39:48 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	static int	g = 0;

	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (nb);
	if (g == 0)
		g = nb / 2;
	if (g * g == nb)
		return (g);
	else if (g * g < nb && (g + 1) * (g + 1) > nb)
		return (0);
	else
	{
		g = (g + nb / g) / 2;
		return (ft_sqrt(nb));
	}
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
