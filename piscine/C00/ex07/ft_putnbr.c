#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*char	int_2_char(int n)
{
	char c;

	c = n + '0';
	return(c);
}
*/

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}	

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}
