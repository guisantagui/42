static int	strlen_til_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	alloc_word(char **word, char const *str, int pos, char c)
{
	int	len;
	int	c_idx;

	len = strlen_til_sep(str + pos, c);
	c_idx = 0;
	*word = (char *)malloc((len + 1) * sizeof(char));
	if (!*word)
		return (-1);
	while (str[pos] != c && str[pos] != '\0')
	{
		(*word)[c_idx] = str[pos];
		pos++;
		c_idx++;
	}
	(*word)[c_idx] = '\0';
	return (pos);
}

char    **ft_split(char const *s, char c)
{
    int		word_num;
	char	**split;
	int		i;
	int		w_idx;

	word_num = word_count(s, c);
	split = (char **)malloc((word_num + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	w_idx = 0;
    while (s[i] && (w_idx < word_num))
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			i = alloc_word(&split[w_idx], s, i, c);
			if (i == -1)
				return (NULL);
			w_idx++;
		}
	}
	split[word_num] = 0;
	return (split);
}