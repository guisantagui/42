#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}

static int	char_in_str(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	f;
	char	*s2;

	i = 0;
	f = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && char_in_str(s1[i], set) == 1)
		i++;
	while (f - 1 != 0 && char_in_str(s1[f - 1], set) == 1)
		f--;
	s2 = ft_substr(s1, i, f - i);
	return (s2);
}

int	main()
{
	char	*str = "Hola que pasa retrasado que tal???";
	const char	*set = "Hola?";

	char	*trimmed = ft_strtrim(str, set);
	printf("%s\n", trimmed);
}
