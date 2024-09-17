int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int	tot_len;
	int	sep_len;
	int	i;

	tot_len = 0;
	sep_len = 0;
	i = 0;
	while (i < size)
	{
		tot_len += ft_strlen((*strs)[i]);
		i++;
	}
	sep_len = ft_strlen(sep);
	joined = (char*)malloc(tot_len + (size - 1) * sep_len);
}
