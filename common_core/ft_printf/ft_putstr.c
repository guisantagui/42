
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}