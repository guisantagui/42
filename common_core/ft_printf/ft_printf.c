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

static int	ft_putptr_rec(unsigned long p)
{
	int	count;

	count = 0;
	if (p == 0)
		ft_putchar('0');
	if (p >= 16)
		count += ft_putptr_rec(p / 16);
	ft_putchar("0123456789abcdef"[p % 16]);
	count++;
	return (count);
}

static int	ft_putptr(unsigned long p)
{
	int	count;

	ft_putstr("0x");
	count = ft_putptr_rec(p) + 2;
	return (count);
}

static int      handle_format(char c, va_list *args)
{
	int	count;
	void	*out;

	if (c == 's')
	{
		out = va_arg(*args, char *);
		count = ft_strlen(out);
		ft_putstr(out);
	}
	else if (c == 'c')
		ft_putchar((char)va_arg(*args, int));
	else if (c == 'p')
		count = ft_putptr((unsigned long)va_arg(*args, void*));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_base(va_arg(*args, int), "0123456789", 1);
	else if (c == 'u')
		count = ft_putnbr_base(va_arg(*args, unsigned int), "0123456789", 0);
	else if (c == 'x')
		count = ft_putnbr_base(va_arg(*args, int), "0123456789abcdef", 0);
	else if (c == 'X')
		count = ft_putnbr_base(va_arg(*args, int), "0123456789ABCDEF", 0);
	else if (c == '%')
		ft_putchar('%');
	if (c == 'c' || c == '%')
		count = 1;
	return (count);
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
