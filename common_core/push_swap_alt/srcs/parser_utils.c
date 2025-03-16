#include "../includes/push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] == '\0')
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (!arr[i])
	{
		free(arr[i]);
		i++;
	}
}

void    error(t_list **lst)
{
    ft_lstclear(lst, free);
	ft_printf("Error\n");
	exit(1);
}