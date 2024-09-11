#include <stdio.h>

int	is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	get_num_ptr_sign(char *str, int *pos)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*pos = i;
	return (sign);
}

int	atoi_cust(char *num)
{
	int	num_len;
        int	num_int;
	int	dix_mult;

	num_len = 0;
	dix_mult = 1;
	while (num[num_len])
		num_len++;
	while (num_len > 1)
	{
		dix_mult *= 10;
		num_len--;
	}
	if (num_len == 0)
		return (0);
	if (*num == '-')
		return (-atoi_cust(num + 1));
	else
		return (*num - '0') * dix_mult + atoi_cust(num + 1);
}

int ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = get_num_ptr_sign(str, &i);
	res = atoi_cust(str + i);
	printf("ft_atoi: %d\n", res);
	res *= sign;
	return (res);
}

int main(void)
{
	char str[] = "  -++--++--1992";
	int     i;
	int	sign = get_num_ptr_sign(str, &i);
	printf("String: %s\n", str + i);
	printf("Sign: %d\n", sign);
	int res = atoi_cust(str);
	//int res2 = atoi(str);
	printf("Res1: %d\n", res);
	//printf("Res2: %d\n", res2);
	return 0;
}
