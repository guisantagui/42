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

static int	ft_putnbr_base(int nbr, char *base, int sig)
{
	unsigned int	num;
	int	b;
	int	count;

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
	{
		num = (unsigned int)nbr;
	}
	if (num >= (unsigned int)b)
		count += ft_putnbr_base(num / b, base, sig);
	ft_putchar(base[num % b]);
	count++;
	return (count);
}

static int	ft_putptr(unsigned long p)
{
	int	count;

	count = 0;
	if (p == 0)
		ft_putchar('0');
	if (p >= 16)
		count += ft_putptr(p / 16);
	ft_putchar("0123456789abcdef"[p % 16]);
	count++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	p_chars;
	void	*out;

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
			if (format[i] == 's')
			{
				out = va_arg(args, char *);
				p_chars += ft_strlen(out);
				ft_putstr(out);
			}
			else if (format[i] == 'c')
			{
				p_chars++;
				ft_putchar((char)va_arg(args, int));
			}
			else if (format[i] == 'p')
			{
				ft_putstr("0x");
				p_chars += ft_putptr((unsigned long)va_arg(args, void*)) + 2;
			}
			else if (format[i] == 'd' || format[i] == 'i')
				p_chars += ft_putnbr_base(va_arg(args, int), "0123456789", 1);
			else if (format[i] == 'u')
				p_chars += ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 0);
			else if (format[i] == 'x')
				p_chars += ft_putnbr_base(va_arg(args, int), "0123456789abcdef", 0);
			else if (format[i] == 'X')
				p_chars += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0);
			else if (format[i] == '%')
			{
				p_chars++;
				ft_putchar('%');
			}
		}
		i++;
	}
	return (p_chars);
}


int	main()
{
	int	a = 10;
	int	*ptr = &a;
	printf("%s, %c, %u, %x, %X, %p, %%\n", "Jose", 'J', -123, -123, 20, (void *)ptr);
	ft_printf("%s, %c, %u, %x, %X, %p, %%\n", "Jose", 'J', -123, -123, 20, (void *)ptr);
	printf("N chars printed: %i\n", ft_putnbr_base(-123, "0123456789", 1));
	printf("N chars printed: %i\n", ft_putnbr_base(-123, "0123456789abcdef", 0));
	printf("N chars printed: %i\n", ft_putptr((unsigned long)ptr));
}
