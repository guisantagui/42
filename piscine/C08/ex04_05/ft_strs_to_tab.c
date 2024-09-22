#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_prev(t_stock_str *stock, int pos)
{
	int	j;

	j = 0;
	while (j <= pos)
	{
		if (stock[j].str != NULL)
			free(stock[j].str);
		if (stock[j].copy != NULL)
			free(stock[j].copy);
		j++;
	}
	free(stock);
}

struct s_stock_str	*ft_strs_to_tab(int c, char **av)
{
	int	i;
	t_stock_str	*stock;

	i = 0;
	stock = (t_stock_str *)malloc((c + 1) * sizeof(t_stock_str));
	if (stock == NULL)
		return NULL;
	while (i < c)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = (char *)malloc((stock[i].size + 1) * sizeof(char));
		if (stock[i].str == NULL)
		{
			free_prev(stock, i);
			return NULL;
		}
		stock[i].str = av[i];
		stock[i].copy = (char *)malloc((stock[i].size + 1) * sizeof(char));
		if (stock[i].copy == NULL)
		{
			free_prev(stock, i);
			return NULL;
		}
		stock[i].copy = ft_strcpy(stock[i].copy, av[i]);
		i++;
	}
	stock[i].size = 0;
	return (stock);
}
