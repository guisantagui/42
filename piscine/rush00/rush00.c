#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	atoi_cust(char *num)
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

void	print_row(int n_col, int is_top_end)
{
	int	j;

	j = 0;
	while (j < n_col)
	{
		if (is_top_end == 0)
		{
			if (j == 0 | j == n_col - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		else
		{
			if (j == 0)
				ft_putchar('A');
			else if (j == n_col - 1)
				ft_putchar('C');
			else
				ft_putchar('B');
		}
		j++;
	}
	ft_putchar('\n');
}

void rush(int n_col, int n_row)
{
	int	i;

	i = 0;
	while (i < n_row)
	{
		if (i == 0 | i == n_row - 1)
			print_row(n_col, 1);
		else
			print_row(n_col, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	n_cols;
	int	n_rows;

	if (argc != 3)
	{
		write(1, "Incorrect number of dimensions!\n", 32);
		return (1);
	}
	else
	{
		n_cols = atoi_cust(argv[1]);
		n_rows = atoi_cust(argv[2]);
		rush(n_cols, n_rows);
	}
}
