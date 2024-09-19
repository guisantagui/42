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
		sep_len = ft_strlen(sep);
		i = 0;
		while (i < size)
		{
			tot_len += ft_strlen(strs[i]);
			if (i < size - 1)
				tot_len += sep_len;
			i++;
		}
		joined = (char*)malloc((tot_len + 1) * sizeof(char));
		if (!joined)
			return (0);
		tot_len = 0;
		i = 0;
		while (i < size)
		{
			j = 0;
			ft_putchar(i + '0');
			ft_putchar('\n');
			while (strs[i][j])
			{
				//ft_putchar(i + '0');
				//ft_putchar('\n');
				//ft_putchar(j + '0');
				//ft_putchar('\n');
				joined[tot_len] = strs[i][j];
				//ft_putchar(strs[i][j]);
				j++;
				tot_len++;
			}
			if (i < size - 1)
			{
				k = 0;
				while (sep[k])
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
