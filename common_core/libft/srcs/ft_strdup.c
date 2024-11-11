static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_strdup(const char *s1)
{
	char	*out;

	out = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	out = ft_strcpy(out, s1);
	return (out);
}
