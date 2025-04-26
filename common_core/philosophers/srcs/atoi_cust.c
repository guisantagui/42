#include "philo.h"

static int	skip_spaces(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

static int	surpasses_int_lims(int res, char c, int sign)
{
	if (sign == 1)
	{
		if (res > (INT_MAX / 10)
			|| (res == INT_MAX / 10 && (c - '0') > (INT_MAX % 10)))
			return (1);
	}
	else if (sign == -1)
	{
		if (res > (-(long)INT_MIN / 10)
			|| (res == -(long)INT_MIN / 10 && (c - '0') > -(INT_MIN % 10)))
			return (1);
	}
	return (0);
}

int	atoi_cust(const char *str, int *is_error)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = skip_spaces(str, &sign);
	while ((str[i] && ft_isdigit(str[i])) && *is_error == 0)
	{
		if (surpasses_int_lims(res, str[i], sign) == 1)
		{
			*is_error = 1;
			return (0);
		}
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return ((int)(sign * res));
}