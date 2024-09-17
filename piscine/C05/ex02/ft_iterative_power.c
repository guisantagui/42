/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:24:27 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/17 22:24:57 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	if (nb == 0 && power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
/*
int	main(void)
{
	int	n = 5;
	int	pow = 3;
	printf("%d to the power of %d is %d.\n", n, pow, ft_iterative_power(n, pow));
	printf("%d to the power of %d is %d.\n", 0, 0, ft_iterative_power(0, 0));
	printf("%d to the power of %d is %d.\n", 1, -4, ft_iterative_power(1, -4));
	printf("%d to the power of %d is %d.\n", 25, 0, ft_iterative_power(25, 0));
}
*/
