#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i++]);
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i++])
	{
		dest[i] = src[i];
	}
	dest[i + 1] = '\0';
	return (dest);
}

int	main(void)
{
	char	str1[20] = "hola caracola";
	char	str2[20];
	ft_strcpy(str2, str1);
	ft_putstr(str2);
}
