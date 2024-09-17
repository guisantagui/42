#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*out;

	out = (char*)malloc(ft_strlen(src) + 1);
	if (!out)
		return (0);
	out = ft_strcpy(out, src);
	return (out);
}
/*
int	main(void)
{
	char	*str1 = "Hola";
	char	*str2 = ft_strdup(str1);
	printf("%s\n", str2);
}
*/
