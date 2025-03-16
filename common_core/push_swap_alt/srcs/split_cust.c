#include "../includes/push_swap.h"

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (is_sep(str[i], charset) == 1)
		i++;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 0)
		{
			count++;
			while (str[i] && (is_sep(str[i], charset) == 0))
				i++;
		}
		else
		{
			i++;
		}
	}
	return (count);
}

static	int strlen_til_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && is_sep(str[i], charset) == 0)
		i++;
	return (i);
}

static int	alloc_word(char **word, char *str, int pos, char *charset)
{
	int	len;
	int	c_idx;

	len = strlen_til_sep(str + pos, charset);
	c_idx = 0;
	*word = (char *)malloc((len + 1) * sizeof(char));
	if (!*word)
		return (-1);
	while (is_sep(str[pos], charset) == 0 && str[pos] != '\0')
	{
		(*word)[c_idx] = str[pos];
		pos++;
		c_idx++;
	}
	(*word)[c_idx] = '\0';
	return (pos);
}

char	**split_cust(char *str, char *charset)
{
	int		word_num;
	char	**split;
	int		i;
	int		w_idx;

	word_num = word_count(str, charset);
	split = (char **)malloc((word_num + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	w_idx = 0;
	while (str[i] && (w_idx < word_num))
	{
		while (is_sep(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
		{
			i = alloc_word(&split[w_idx], str, i, charset);
			if (i == -1)
				return (NULL);
			w_idx++;
		}
	}
	split[word_num] = 0;
	return (split);
}