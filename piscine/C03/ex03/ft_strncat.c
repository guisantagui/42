//#include <stdio.h>
//#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (src[i] != '\0' && i < nb)
	{
		dest[len + i] = src[i];
		i++;
	}

	dest[len + i] = '\0';
	return (dest);
}

/*int	main()
{
	char str1[50] = "Hola";
	char str2[20] = "Hola";

	ft_strncat(str1, str2, 5);
	printf("Result: %s\n", str1);
}*/
