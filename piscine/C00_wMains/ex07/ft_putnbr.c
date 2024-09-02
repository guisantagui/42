#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	int_2_char(int n)
{
	char c;

	c = n + '0';
	return(c);
}


void	ft_putnbr(int nb)
{       int divisor;
	int digit;
	char digitC;	

	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}

	divisor = 1;
    	while (nb / divisor >= 10)
	{
		divisor *= 10;
	}

while (divisor > 0)
	{
		digit = nb / divisor;
		digitC = int_2_char(digit);
		ft_putchar(digitC);
		nb = nb % divisor;
		divisor /= 10;
	}
}

int	main()
{
	int num;
	int numNeg;	
	int numNeg2;

	num = 123;
	numNeg = -234;
	numNeg2 = -2147482648;
	ft_putnbr(num);
	ft_putnbr(numNeg);
	ft_putnbr(numNeg2);
}
