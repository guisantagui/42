#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);
void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush04(int x, int y);


int	main()
{
	int	x;
	int	y;
	int	style;

	x = 5;
	y = 5;
	style = 5;
	if (x >= 0 && y >= 0)
	{
		if (style == 1)
			rush(x, y);
		else if (style == 2)
			rush00(x, y);
		else if (style == 3)
			rush01(x, y);
		else if (style == 4)
			rush02(x, y);
		else if (style == 5)
			rush04(x, y);
		else
			write(1, "Style not supported\n", 20);
	}
}
