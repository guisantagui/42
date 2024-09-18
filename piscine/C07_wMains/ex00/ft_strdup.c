#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*out;

	out = (char*)malloc(ft_strlen(src) * sizeof(char));
	out = src;
	return (out);
}

int	main(void)
{
	char	*str1 = "Hola";
	char	*str2 = ft_strdup(str1);
	printf("%s\n", str2);
}
