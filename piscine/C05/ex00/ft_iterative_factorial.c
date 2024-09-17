/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:22:25 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/17 22:23:10 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	else
	{
		result = 1;
		while (nb > 1)
		{
			result *= nb;
			nb--;
		}
		return (result);
	}
}
/*
int	main(void)
{
	printf("Factorial of %d:\n", 5);
	printf("%d\n", ft_iterative_factorial(5));
	printf("Factorial of %d:\n", -5);
        printf("%d\n", ft_iterative_factorial(-5));
}
*/
