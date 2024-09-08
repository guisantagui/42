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

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str1[20] = "hola caracola";
	ft_strupcase(str1);
	ft_putstr(str1);
}
