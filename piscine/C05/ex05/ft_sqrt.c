//#include <stdio.h>

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (nb);
	static int	g = 0;
	if (g == 0)
		g = nb / 2;
	if (g * g == nb)
		return (g);
	else if (g * g < nb && (g + 1) * (g + 1) > nb)
		return (0);
	else
	{
		g = (g + nb / g) / 2;
		return (ft_sqrt(nb));
	}
}
/*
int	main()
{
	int	num = 26;
	int     num1 = 25;
	int     num2 = 16;
	int     num3 = 100;
	printf ("sqrt(%d) = %d\n", num, ft_sqrt(num));
	printf ("sqrt(%d) = %d\n", num1, ft_sqrt(num1));
	printf ("sqrt(%d) = %d\n", num2, ft_sqrt(num2));
	printf ("sqrt(%d) = %d\n", num3, ft_sqrt(num3));
}
*/
