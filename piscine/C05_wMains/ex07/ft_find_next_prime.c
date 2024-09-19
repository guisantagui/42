#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	div;

	div = 2;
	if (nb < 2 || nb == 2147483647)
		return (0);
	while (div <= nb)
	{
		if (nb == div)
			return (1);
		else if (nb % div == 0)
			return (0);
		else
			div++;
	}
	return (0);
}
/*
int	is_prime_help(int nb, int div)
{
	if (nb < 2)
		return (0);
	else if (nb == div)
		return (1);
	else if (nb % div == 0)
		return (0);
	else
		return (is_prime_help(nb, div + 1));

}

int	ft_is_prime(int nb)
{
	int     div;

	div = 2;
	return (is_prime_help(nb, div));
}
*/
int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}

int	main()
{
	int n1 = 3;
	int n2 = 16;
	int n3 = 71;
	int n4 = 81;
	printf("%d: %d\n", n1, ft_find_next_prime(n1));
	printf("%d: %d\n", n2, ft_find_next_prime(n2));
	printf("%d: %d\n", n3, ft_find_next_prime(n3));
	printf("%d: %d\n", n4, ft_find_next_prime(n4));
}
