#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (src[i] != '\0' && i < nb)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (src[i] != '\0')
		dest[len + i] = '\0';
	return (dest);
}

int	main()
{
	char str1[50] = "Hola, ";
	char str2[20] = "Mundo!";

	ft_strncat(str1, str2, 3);
	printf("Result: %s\n", str1);
}
