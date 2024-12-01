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

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putnbr_base(int nbr, char *base)
{
	int	b;

	b = ft_strlen(base);
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putnbr_base(-(nbr / b), base);
		}
		else
		{
			ft_putchar('-');
			nbr *= -1;
		}
	}
	if (nbr >= b)
		ft_putnbr_base(nbr / b, base);
	write(1, &base[nbr % b], 1);
}

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
			ft_putchar(format[i]);
		else
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i] == 'c')
				ft_putchar((char)va_arg(args, int));
			else if (format[i] == 'd')
				ft_putnbr_base(va_arg(args, int), "0123456789");
			else if (format[i] == 'x')
			{
				printf("Hola\n");
				int	n = va_arg(args, int);
				printf("%d\n", n);
				ft_putnbr_base(n, "0123456789abcdef");
			}
			else if (format[i] == 'X')
				ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
		}
		i++;
	}
}


int	main()
{
	printf("%s, %c, %d, %x, %X\n", "Jose", 'J', 123, -123, 20);
	ft_printf("%s, %c, %d, %x, %X\n", "Jose", 'J', 123, -123, 20);
}
