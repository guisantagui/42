#include <stdlib.h>


int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (is_sep(str[i], charset) == 1)
		i++;
	while (str[i])
	{
		while (is_sep(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (is_sep(str[i], charset) == 0)
				i++;
		}
	}
	return (count);
}

char	*alloc_word(int len)
{
	char	*word;

	word = (char *)malloc((len + 1) * sizeof(char));
	return (word);
}



char	**ft_split(char *str, char *charset)
{
	int	word_num;
	char	**split;
	int	i;
	int	w_idx;
	int	c_idx;

	word_num = word_count(str, charset);
	split = (char *)malloc((word_num + 1) * sizeof(char));
	i = 0;
	w_idx = 0;
	c_idx = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset) == 1)
			i++;
		while (is_sep(str[i], charset) == 0)
		{
			split[w_idx][c_idx] = str[i];
			i++;
			c_idx++;
		}
		if (is_sep(str[i], charset) == 1)
		{
			split[w_idx][c_idx] = '\0';
			w_idx++;
			c_idx = 0;
		}
	}
}
