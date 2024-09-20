#include <stdio.h>
/*
int	ft_sqrt(int nb)
{
	int	i;
	if (nb < 0 || nb > 2147395600)
		return (0);
	else
	{
		i = 0;
		while (i * i <= nb)
		{
			if (i * i == nb)
				return (i);
			else
			i++;
		}
		return (0);
	}
}
*/
int	sqrt_help(int nb, int g)
{
	if (nb < 0 || nb > 2147395600)
		return (0);
	else if (nb == 0 || nb == 1)
		return (nb);
	else if (g * g == nb)
		return (g);
	else if (g * g < nb && (g + 1) * (g + 1) > nb)
		return (0);
	else
		return(sqrt_help(nb, (g + nb / g) / 2));
}

int	ft_sqrt(int nb)
{
	int	g;

	g = nb / 2;
	return (sqrt_help(nb, g));
}

int	main()
{
	int	num = 26;
	int     num1 = 25;
	int     num2 = 16;
	int     num3 = 100;
	int	num4 = -4;
	int	num5 = 2147483647;
	int	num6 = 2147395599;
	int     num7 = 3;
	int	num8 = 9;
	int     num9 = 0;
	int     num10 = 1000000;
	printf ("sqrt(%d) = %d\n", num, ft_sqrt(num));
	printf ("sqrt(%d) = %d\n", num1, ft_sqrt(num1));
	printf ("sqrt(%d) = %d\n", num2, ft_sqrt(num2));
	printf ("sqrt(%d) = %d\n", num3, ft_sqrt(num3));
	printf ("sqrt(%d) = %d\n", num4, ft_sqrt(num4));
	printf ("sqrt(%d) = %d\n", num5, ft_sqrt(num5));
	printf ("sqrt(%d) = %d\n", num6, ft_sqrt(num6));
	printf ("sqrt(%d) = %d\n", num7, ft_sqrt(num7));
	printf ("sqrt(%d) = %d\n", num8, ft_sqrt(num8));
	printf ("sqrt(%d) = %d\n", num9, ft_sqrt(num9));
	printf ("sqrt(%d) = %d\n", num10, ft_sqrt(num10));
}
