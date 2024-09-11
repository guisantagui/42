#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char *digits;

	digits = "0123456789";
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
		}
		else
			ft_putnbr(-nb);
	}
	else if (nb >= 10)
		ft_putnbr(nb / 10);
	
	write(1, &digits[nb % 10], 1);
}

int	main()
{
	int	n;

	n = 1992;
	ft_putnbr(n);
}
