/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:35:10 by gsantama          #+#    #+#             */
/*   Updated: 2025/01/11 15:35:13 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_rec(unsigned long p)
{
	int	count;

	count = 0;
	if (p >= 16)
		count += ft_putptr_rec(p / 16);
	ft_putchar("0123456789abcdef"[p % 16]);
	count++;
	return (count);
}

int	ft_putptr(unsigned long p)
{
	int	count;

	ft_putstr("0x");
	count = ft_putptr_rec(p) + 2;
	return (count);
}
