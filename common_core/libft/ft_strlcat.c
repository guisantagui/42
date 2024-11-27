#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (dst[len] && len < dstsize)
		len++;
	if (dstsize <= len)
		return (len + ft_strlen(src));
	while (src[i] != '\0' && (len + i + 1) < dstsize)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
