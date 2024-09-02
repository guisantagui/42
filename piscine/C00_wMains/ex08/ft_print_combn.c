/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:37:41 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/02 18:43:13 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	int_2_char(int n)
{
	char c;

	c = n + '0';
	return(c);
}

void	ft_print_combn(int n)
{
	int num;
	int count;
	char nOut;

	count = 0;
	while (count < n)
	{
		num = 0 + count;
		while (num < 10 - count)
		{
			nOut = int_2_char(num);
			ft_putchar(nOut);
			num++;
		}
		ft_putchar(',');
		ft_putchar(' ');
		count++;
	}
}

int 	main()
{
	int numero;

	numero = 4;
	ft_print_combn(numero);
}
