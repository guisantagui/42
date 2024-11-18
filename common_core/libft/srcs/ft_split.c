#include <stdio.h>
#include <stdlib.h>

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

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && (s[i] != c))
				i++;
		}
		else
		{
			while (s[i] == c)
				i++;
		}
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

void	free_arr(char **arr, int len)
{
	int	i;

	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char    **ft_split(char const *s, char c)
{
    int		word_num;
	char	**split;
	int		i;
	int		w_idx;

	word_num = word_count(s, c);
	split = (char **)malloc((word_num + 1) * sizeof(char *));
	if (!s || !split)
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
			{
				free_arr(split, w_idx);
				return (NULL);
			}
			w_idx++;
		}
	}
	split[word_num] = 0;
	return (split);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	i;
		char	**split;

		split = ft_split(argv[1], argv[2][0]);
		i = 0;
		while (split[i] != 0)
		{
			printf("%s\n", split[i]);
			i++;
		}
	}
}