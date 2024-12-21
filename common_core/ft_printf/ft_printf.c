/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:48:22 by gsantama          #+#    #+#             */
/*   Updated: 2024/12/01 19:55:55 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	p_chars;

	va_start(args, format);
	i = 0;
	p_chars = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			p_chars++;
		}
		else
		{
			i++;
			p_chars += handle_format(format[i], &args);
		}
		i++;
	}
	return (p_chars);
}