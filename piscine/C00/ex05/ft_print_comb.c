/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:07:22 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/03 20:58:21 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_comb(int n1, int n2, int n3)
{
	ft_putchar(n1 + '0');
	ft_putchar(n2 + '0');
	ft_putchar(n3 + '0');
	if (!(n1 == 7 && n2 == 8 && n3 == 9))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	num1;
	int	num2;
	int	num3;
	int	count_shift;

	num1 = 0;
	count_shift = 0;
	while (num1 <= 7)
	{
		count_shift = 0;
		num2 = 1 + num1 + count_shift;
		while (num2 <= 8)
		{
			num3 = num2 + 1;
			while (num3 <= 9)
			{
				write_comb(num1, num2, num3);
				num3++;
			}
			num2++;
			count_shift++;
		}
		num1++;
	}
}
