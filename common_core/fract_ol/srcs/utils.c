#include "fractol.h"

int    is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\f'
        || c == '\r' || c == '\n' || c == '\v')
        return (1);
    else
        return (0);
}

int    skip_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i] && is_space(str[i]))
        i++;
    if (str[i] == '0' && str[i + 1] && (ft_toupper(str[i + 1]) == 'X'))
        i += 2;
    return (i);
}

void    free_arr(char **arr)
{
    int i;

    i = 0;
    if (!arr)
        return ;
    while (arr[i] != NULL)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int	ft_atoi_cust(const char *str, int *sign)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (*sign * res);
}