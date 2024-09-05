#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*cuerda;
	int	len;

	cuerda = "cuerda";
	len = ft_strlen(cuerda);
	len = len + '0';
	write(1, &len, 1);
}
