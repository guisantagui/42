#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int nb)
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
	else
	{
		ft_putchar(nb + '0');
	}
}

int	main()
{
	int num;
	int numNeg;	
	int numNeg2;

	num = 123;
	numNeg = -234;
	numNeg2 = -2147483648;
	ft_putnbr(num);
	ft_putnbr(numNeg);
	ft_putnbr(numNeg2);
	ft_putnbr(-42);
}
