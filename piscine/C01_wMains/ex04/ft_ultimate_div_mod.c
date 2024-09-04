#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
        if(nb <= 2147483647 && nb >= -2147483648)
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


void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;

	*a = div;
	*b = mod;
}

int	main()
{
	int	n1;
	int	n2;

	n1 = 25;
	n2 = 10;

	ft_ultimate_div_mod(&n1, &n2);
	ft_putnbr(n1);
        ft_putchar(' ');
        ft_putnbr(n2);

}

