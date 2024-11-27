#include "libft.h"

static char	*substr_chk(const char *str, const char *to_find, size_t pos, size_t len)
{
	size_t	f_match;
	size_t	i;

	f_match = pos;
	i = 0;
	while (str[pos] == to_find[i] && to_find[i] != '\0' && str[pos] != '\0' && (pos + i) < len)
	{
		i++;
		pos++;
	}
	if (i == len)
		return ((char *)str + f_match);
	else
		return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		j;
	char	*p_out;

	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j] != '\0' && j < len)
	{
		if (haystack[j] == needle[0])
		{
			p_out = substr_chk(haystack, needle, j, len);
			if (p_out != NULL)
				return (p_out);
		}
		j++;
	}
	return (NULL);
}
