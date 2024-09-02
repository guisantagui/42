#include <unistd.h>

void	ft_print_numbers(void)
{
	int	num;
	char    toOut;

	num = 0;
	while (num <= 9)
	{
		toOut = num + '0';
		write (1, &toOut, 1);
		num++;
	}
}