#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}
