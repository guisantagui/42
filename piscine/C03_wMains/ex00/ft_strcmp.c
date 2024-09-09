#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb <= 2147483647 && nb >= -2147483648)
	{
		if (nb == -2147483648)
		{
			ft_putchar('-');
			ft_putchar('2');
			ft_putnbr(147483648);
		}
		else if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
			ft_putnbr(nb);
		}
		else if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putchar(nb + '0');
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	out;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		out = 0;
	else
		out = (s1[i] - s2[i]);
	return (out);
}

int	main()
{
	char s1[20] = "Hola";
	char s2[20] = "HOla";
	char s3[20] = "Perro";
	char s4[20] = "Holamanola";

	ft_putnbr(ft_strcmp(s1, s1));
	ft_putnbr(ft_strcmp(s1, s2));
	ft_putnbr(ft_strcmp(s2, s3));
	ft_putnbr(ft_strcmp(s3, s4));
}
