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

void	ft_putnbr(int nb)
{
	if(nb <= 2147483647 && nb >= -2147483648)
	{
		if(nb == -2147483648)
		{
			ft_putchar('-');
			ft_putchar('2');
			ft_putnbr(147483648);
		}
		else if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
                	ft_putnbr(nb);
		}	

		else if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else{
			ft_putchar(nb + '0');
		}
	}
	
}

void create_combs(int n, int comb, int pos)
{
	int i;
	i = 0;
	if (pos == n)
	{
		ft_putnbr(n);
	}

	while (i <= 9)
	{
		create_combs(n, comb * 10 + i, pos + 1);
		if (pos == n - 1 && i < 9)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	create_combs(n, 0, 0);
}

int 	main()
{
	int numero;

	numero = 4;
	ft_print_combn(numero);
}
