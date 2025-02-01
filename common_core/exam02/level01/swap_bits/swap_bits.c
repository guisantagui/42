#include <unistd.h>
#include <stdlib.h>


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
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

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_putstr("bit: ");
		print_bits((unsigned char)atoi(av[1]));
		write(1, "\n", 1);
		ft_putstr("swapped bit: ");
		print_bits(swap_bits((unsigned char)atoi(av[1])));
	}
	write(1, "\n", 1);
}
