#include <unistd.h>
#include <stdlib.h>

void    ft_putstr(char *str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                write(1, &str[i], 1);
                i++;
        }
}

void	print_bits(unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = (bit << 1) | (octet & 1);
		octet >>= 1;
		i--;
	}
	return (bit);
}

int     main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_putstr("bit: ");
		print_bits((unsigned char)atoi(av[1]));
		write(1, "\n", 1);
		ft_putstr("rev: ");
		print_bits(reverse_bits((unsigned char)atoi(av[1])));
	}
	write(1, "\n", 1);
}


