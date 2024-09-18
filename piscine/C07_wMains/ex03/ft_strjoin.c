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
	int	j;
	int	k;

	if (size == 0)
	{
		joined = (char*)malloc(1 * sizeof(char));
		joined[0] = '\0';
	}
	else
	{
		tot_len = 0;
		sep_len = 0;
		i = 0;
		j = 0;
		k = 0;
		while (i < size)
		{
			tot_len += ft_strlen((*strs)[i]);
			i++;
		}
		tot_len++;
		sep_len = ft_strlen(sep);
		joined = (char*)malloc((tot_len + (size - 1) * sep_len) * sizeof(char));
		tot_len = 0;
		while (i < size)
		{
			while (j < ft_strlen((*strs)[i]))
			{
				joined[tot_len] = (*strs)[i][j];
				j++;
				tot_len++;
			}
			if (i < size - 1)
			{
				while (k < sep_len)
				{
					joined[tot_len] = sep[k];
					k++;
					tot_len++;
				}
			}
			i++;
		}
		joined[tot_len] = '\0';
	}
	return (joined);
}
