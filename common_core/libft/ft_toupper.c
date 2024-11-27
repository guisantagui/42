#include "libft.h"

char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
