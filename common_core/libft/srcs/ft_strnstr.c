char	*substr_chk(const char *str, const char *to_find, size_t pos, size_t len)
{
	size_t	f_match;
	size_t	i;

	f_match = pos;
	i = 0;
	while (str[pos] == to_find[i] && to_find[i] != '\0' && str[pos] != '\0' && i < len)
	{
		i++;
		pos++;
	}
	if (i == len)
		return (str + f_match);
	else
		return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		j;
	char	*p_out;

	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[j] != '\0')
	{
		if (str[j] == to_find[0])
		{
			p_out = substr_chk(hayshack, needle, j, len);
			if (p_out != NULL)
				return (p_out);
		}
		j++;
	}
	return (NULL);
}
