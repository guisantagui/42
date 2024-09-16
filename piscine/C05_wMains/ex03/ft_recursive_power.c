#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (ft_recursive_power(nb, power - 1) * nb);
}

int	main()
{
	int	n;
	int	p;
	n = 2;
	p = 3;
	printf("%d to the power of %d = %d\n", n, p, ft_recursive_power(n, p));
}
