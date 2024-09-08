void	ft_putchar(char c);
void    print_row(int n_col, int is_top_end, char c_1, char c_2, char mid)
{
	int     j;

	j = 0;
	while (j < n_col)
	{
		if (is_top_end == 0)
		{
			if (j == 0 | j == n_col - 1)
				ft_putchar(c_1);
			else
				ft_putchar(mid);
		}
		else
		{
			if (j == 0)
				ft_putchar(c_1);
			else if (j == n_col - 1)
				ft_putchar(c_2);
			else
				ft_putchar(mid);
		}
		j++;
	}
	ft_putchar('\n');
}

void rush(int x, int y)
{
	int     i;
	while (i < y)
	{
		if (i == 0 | i == y - 1)
			print_row(x, 1, 'A', 'C', 'B');
		else
			print_row(x, 0, 'B', 'B', ' ');
		i++;
	}
}

void rush00(int x, int y)
{
	int	i;
	while (i < y)
	{
		if (i == 0 | i == y - 1)
			print_row(x, 1, 'o', 'o', '-');
		else
			print_row(x, 0, '|', '|', ' ');
		i++;
	}
}

void rush01(int x, int y)
{
	int	i;
	while (i < y)
	{
		if (i == 0)
			print_row(x, 1, '/', '\\', '*');
		else if (i == y - 1)
			print_row(x, 1, '\\', '/', '*');
		else    
			print_row(x, 0, '*', '*', ' ');
		i++;
	}
}

void rush02(int x, int y)
{
	int	i;
	while (i < y)
	{
		if (i == 0)
			print_row(x, 1, 'A', 'A', 'B');
		else if (i == y - 1)
			print_row(x, 1, 'C', 'C', 'B');
		else
			print_row(x, 0, 'B', 'B', ' ');
		i++;
	}
}

void rush04(int x, int y)
{
	int	i;
	while (i < y)
	{
 		if (i == 0)
			print_row(x, 1, 'A', 'C', 'B');
		else if (i == y - 1)
			print_row(x, 1, 'C', 'A', 'B');
		else
			print_row(x, 0, 'B', 'B', ' ');
		i++;
	}
}





