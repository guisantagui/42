#include <stdlib.h>
#include <stdio.h>

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

int	strlen_til_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && is_sep(str[i], charset) == 0)
		i++;
	return (0);
}

int	alloc_word(char *word, char *str, int pos, char *charset)
{
	int	len;
	int	c_idx;

	len = strlen_til_sep(str + pos, charset);
	c_idx = 0;
	word = (char *)malloc((len + 1) * sizeof(char));
	while (is_sep(str[pos], charset) == 0 && str[pos] != '\0')
	{
		word[c_idx] = str[pos];
		pos++;
		c_idx++;
	}
	word[c_idx] = '\0';
	return (pos);
}

char	**ft_split(char *str, char *charset)
{
	int	word_num;
	char	**split;
	int	i;
	int	w_idx;

	word_num = word_count(str, charset);
	split = (char *)malloc((word_num + 1) * sizeof(char));
	i = 0;
	w_idx = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset) == 1)
			i++;
		i = alloc_word(split[w_idx], str, i, charset);
		if (is_sep(str[i], charset) == 1)
		{
			split[w_idx][c_idx] = '\0';
			w_idx++;
			c_idx = 0;
		}
	}
	split[w_idx] = 0;
	return (split);
}

int	main()
{
	char to_split = "Hola, aqui.estamos:quepasa";
	char sep = ",.:";
	char **split = ft_split(to_split, sep);
	int	w;

	w = 0;
	while (split[w] != 0)
	{
		printf("%s\n", split[w]);
		w++;
	}
}

