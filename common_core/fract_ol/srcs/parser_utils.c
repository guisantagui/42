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

double  ft_atod(char *str)
{
    double res;
    int i;
    double dec_div;
    char    **split;
    int sign;

    res = 0;
    dec_div = 1;
    split = ft_split(str, '.');
    sign = 1;
    res = (double)ft_atoi_cust(split[0], &sign);
    if (split[1] != NULL)
    {
        i = skip_spaces(split[1]);
        while (split[1][i] && ft_isdigit(split[1][i]))
        {
            dec_div *= 0.1;
            res += (split[1][i] - '0') * dec_div;
            i++;
        }
    }
    free_arr(split);
    return (res * sign);
}