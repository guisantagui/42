#include <stdlib.h>
#include <stdio.h>

int	get_size(int nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		size++;
		nbr /= 10;
	}
	size++;
	return (size);
}



char	*ft_itoa(int nbr)
{
	int	i;
	int	size;
	char	*str;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	i = 0;
	size = get_size(nbr);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[i] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[--size] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("Introduced number: %s\nITOA number: %s\n", av[1], ft_itoa(atoi(av[1])));
	}
}
