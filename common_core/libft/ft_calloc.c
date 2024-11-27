#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	else if (((count * size) / size) != count)
		return (NULL);
	out = malloc(count * size);
	if (!out)
		return (NULL);
	ft_memset(out, 0, count * size);
	return (out);
}
