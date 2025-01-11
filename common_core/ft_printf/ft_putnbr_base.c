/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:27:34 by gsantama          #+#    #+#             */
/*   Updated: 2025/01/11 15:33:54 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nbr, char *base, int sig)
{
	unsigned int	num;
	int				b;
	int				count;

	count = 0;
	b = ft_strlen(base);
	if (nbr < 0)
	{
		if (b == 10 && sig == 1)
		{
			ft_putchar('-');
			nbr = -nbr;
			count++;
		}
		num = (unsigned int)nbr;
	}
	else
		num = (unsigned int)nbr;
	if (num >= (unsigned int)b)
		count += ft_putnbr_base(num / b, base, sig);
	ft_putchar(base[num % b]);
	count++;
	return (count);
}
