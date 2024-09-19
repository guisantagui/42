#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	get_tot_len(int size, char **strs, char *sep)
{
	int	tot_len;
	int	sep_len;
	int	i;

	tot_len = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		tot_len += ft_strlen(strs[i]);
		if (i < size - 1)
			tot_len += sep_len;
		i++;
	}
	return (tot_len);
}

char	*get_joined(int pointLen)
{
	char	*joined;

	joined = (char *)malloc(pointLen * sizeof(char));
	return (joined);
}

void	concat_to_str(char *joined, char **strs, char *sep, int size)
{
	int	tot_len;
	int	i;
	int	j;
	int	k;

	tot_len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			joined[tot_len++] = strs[i][j++];
		if (i < size - 1)
		{
			k = 0;
			while (sep[k])
				joined[tot_len++] = sep[k++];
		}
		i++;
	}
	joined[tot_len] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int	tot_len;

	tot_len = get_tot_len(size, strs, sep);
	joined = get_joined(tot_len + 1);
	if (!joined)
		return (0);
	concat_to_str(joined, strs, sep, size);
	return (joined);
}

int	main()
{
	char *strings[] = {
		"Hello",
		"World",
		"This",
		"Is",
		"C"};
	char *sep = ", ";
	char *joined = ft_strjoin(5, strings, sep);
	printf("%s\n", joined);
}
