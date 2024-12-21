#include "ft_printf.h"

int	handle_format(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (c == 'c')
		count = ft_putchar((char)va_arg(*args, int));
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
		count = ft_putchar('%');
	return (count);
}