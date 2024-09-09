char	*ft_strcapitalize(char *str)
{
	int	i;
	int	w_idx;

	i = 0;
	w_idx = 0;
	while(str[i])
	{
		if ((str[i] >= 97 && str[i] <= 122) && w_idx == 0)
			str[i] = str[i] - 32;
		else if ((str[i] >= 65 && str[i] <= 90) && w_idx != 0)
			str[i] = str[i] + 32;
		if (!((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 48 && str[i] <= 57)))
			w_idx = 0;
		else
			w_idx++;
		i++;
	}
	return (str);
}
