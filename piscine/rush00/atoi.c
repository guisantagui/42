#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

int     atoi_cust(char *num)
{
        int     num_len;
        int     num_int;
        int     dix_mult;

        num_len = 0;
        dix_mult = 1;
        while (num[num_len])
                num_len++;
	while (num_len > 1)
	{
		dix_mult *= 10;
		num_len--;
	}
        if (num_len == '\0')
                return (0);
        else	
                return (*num - '0') * dix_mult + atoi_cust(num + 1);
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

int     main(int argc, char **argv)
{
        int     n_cols;
        int     n_rows;

        if (argc != 3)
        {
                write(1, "Incorrect number of dimensions!\n", 32);
                return (1);
        }
        else
        {
                n_cols = atoi_cust(argv[1]);
                n_rows = atoi_cust(argv[2]);
                ft_putnbr(n_cols);
		ft_putnbr(n_rows);
        }
}

