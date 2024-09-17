/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:35:24 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/17 19:46:08 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_is_prime(int nb)
{
	static int	div = 2;

	if (nb < 2)
		return (0);
	else if (nb == div)
	{
		div = 2;
		return (1);
	}
	else if (nb % div == 0)
		return (0);
	div += 1;
	return (ft_is_prime(nb));
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
/*
int	main()
{
	int n1 = 3;
	int n2 = 16;
	int n3 = 71;
	int n4 = 81;
	printf("%d: %d\n", n1, ft_find_next_prime(n1));
	printf("%d: %d\n", n2, ft_find_next_prime(n2));
	printf("%d: %d\n", n3, ft_find_next_prime(n3));
	printf("%d: %d\n", n4, ft_find_next_prime(n4));
}
*/
