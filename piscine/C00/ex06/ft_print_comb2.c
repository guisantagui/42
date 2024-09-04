/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:03:40 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/04 19:10:42 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	int_2_char(int n)
{
	char	c;

	c = n + '0';
	return (c);
}

void	num_two_dig(int n)
{
	int		units;
	int		tens;
	char	units_c;
	char	tens_c;

	units = n % 10;
	tens = (n - units) / 10;
	units_c = int_2_char(units);
	tens_c = int_2_char(tens);
	ft_putchar(tens_c);
	ft_putchar(units_c);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 < 99)
	{
		num2 = num1 + 1;
		while (num2 < 100)
		{
			if (num1 != num2)
			{
				num_two_dig(num1);
				ft_putchar(' ');
				num_two_dig(num2);
				if (!(num1 == 98 && num2 == 99))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			num2++;
		}
		num1++;
	}
}
