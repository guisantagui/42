#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

/*int	main()
{
	char	string[10] = "Hola!";
	printf("Length: %d\n", ft_strlen(string));
}*/
