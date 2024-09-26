#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_count_if(char **tab, int(*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

int	has_char(char *str)
{
	int	i;
	char	c;

	i = 0;
	c = 'a';
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main()
{
	char *tab[6];
	tab[0] = strdup("Hola");
	tab[1] = strdup("adios");
	tab[2] = strdup("quetal");
	tab[3] = strdup("quepasa");
	tab[4] = strdup("aquiestamos");
	tab[5] = 0;
	printf("%d\n", ft_count_if(tab, has_char));
}
