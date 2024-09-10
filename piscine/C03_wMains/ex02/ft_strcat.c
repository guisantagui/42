#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = src[i];
	return (dest);
}

int	main()
{
	char str1[50] = "Hola, ";
	char str2[20] = "Mundo!";

	ft_strcat(str1, str2);
	printf("Result: %s\n", str1);
}
