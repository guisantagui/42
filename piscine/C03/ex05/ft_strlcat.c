//#include <stdio.h>
//#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	if (len < size)
	{
		while (src[i] != '\0' && (i <= size - len - 1))
		{
			dest[len + i] = src[i];
			i++;
		}
		dest[len + i] = '\0';
		return (len + i);
	}
	else
	{
		return (len + size);
	}
}

/*int	main()
{
	char str1[10] = "Hola, ";
	char str2[20] = "Mundo!";
	int tot_len;

	tot_len = ft_strlcat(str1, str2, 10);
	printf("Result: %s\n", str1);
	printf("Total length: %d\n", tot_len);
}*/
