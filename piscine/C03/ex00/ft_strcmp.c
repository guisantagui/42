//#include <unistd.h>
//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/*int	main()
{
	char s1[20] = "Hola";
	char s2[20] = "HOla";
	char s3[20] = "Perro";
	char s4[20] = "Holamanola";

	printf("%d\n", ft_strcmp(s1, s1));
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", ft_strcmp(s2, s3));
	printf("%d\n", ft_strcmp(s3, s4));
}*/
