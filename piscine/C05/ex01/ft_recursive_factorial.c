/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:35:56 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/17 19:36:44 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
		return (ft_recursive_factorial(nb - 1) * nb);
}
/*
int	main(void)
{
	printf("Factorial of %d is %d.\n", 5, ft_recursive_factorial(5));
	printf("Factorial of %d is %d.\n", -5, ft_recursive_factorial(-5));
}
*/
