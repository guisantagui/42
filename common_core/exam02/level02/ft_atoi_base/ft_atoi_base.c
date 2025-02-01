#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c +=32;
	return (c);
}

int	get_digit(char c, int str_base)
{
	char base[17] = "0123456789abcdef";
	int	i;

	i = 0;
	if (str_base > 16 || str_base < 2)
		return (-1);
	while (i < str_base)
	{
		if (base[i] == to_lower(c))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;

	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && get_digit(str[i], str_base) >= 0)
	{
		res = res * str_base + get_digit(str[i], str_base);
		i++;
	}
	res *= sign;
	return (res);	
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%s is %d", av[1], ft_atoi_base(av[1], ft_atoi_base(av[2], 10)));
	}
	printf("\n");
}
