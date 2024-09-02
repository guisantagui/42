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
	if(nb <= 2147483647 && nb >= -2147483648)
	{
		if(nb == -2147483648)
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
		else{
			ft_putchar(nb + '0');
		}
	}
	
}
