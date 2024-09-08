#include <urush00_def.nistd.h>

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
	if (*num == '-')
		return (-atoi_cust(num + 1));
	else
		return (*num - '0') * dix_mult + atoi_cust(num + 1);
}

void	print_row(int n_col, int is_top_end, char c_1, char c_2, char mid)
{
	int	j;

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


void rush(int n_col, int n_row, int style)
{
	int	i;
	char	vert_mid;
	char	edge_mid;
	char	vert1_first;
	char	vert2_first;
	char	edge_first;
	char	vert1_last;
	char	vert2_last;

	if(style == 1)
	{
		vert_mid = '|';
		edge_mid = ' ';
		vert1_first = 'o';
		vert2_first = 'o';
		edge_first = '-';
	}
	else if (style == 2)
	{
		vert_mid = '*';
		edge_mid = ' ';
		vert1_first = '/';
		vert2_first = '\\';
		edge_first = '*';
		vert1_last = '\\';
		vert2_last = '/';
	}
	else if (style == 3)
	{
		vert_mid = 'B';
		edge_mid = ' ';
		vert1_first = 'A';
		vert2_first = 'A';
		edge_first = 'B';
		vert1_last = 'C';
		vert2_last = 'C';
	}
	else if (style == 4)
	{
		vert_mid = 'B';
		edge_mid = ' ';
		vert1_first = 'A';
		vert2_first = 'C';
		edge_first = 'B';
	}
	else if (style == 5)
	{
		vert_mid = 'B';
		edge_mid = ' ';
		vert1_first = 'A';
		vert2_first = 'C';
		edge_first = 'B';
		vert1_last = 'C';
		vert2_last = 'A';
	}

	i = 0;
	if (style == 1 | style == 4)
	{
		while (i < n_row)
		{
			if (i == 0 | i == n_row - 1)
				print_row(n_col, 1, vert1_first, vert2_first, edge_first);
			else
				print_row(n_col, 0, vert_mid, vert_mid, edge_mid);
			i++;
		}
	}
	else if (style == 2 | style == 3 | style == 5)
	{
		while (i < n_row)
		{
			if (i == 0)
				print_row(n_col, 1, vert1_first, vert2_first, edge_first);
			else if (i == n_row - 1)
				print_row(n_col, 1, vert1_last, vert2_last, edge_first);
			else
				print_row(n_col, 0, vert_mid, vert_mid, edge_mid);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	n_cols;
	int	n_rows;
	int	style;

	if (argc != 4)
	{
		write(1, "Incorrect number of dimensions!\n", 32);
		return (1);
	}
	else
	{
		n_cols = atoi_cust(argv[1]);
		n_rows = atoi_cust(argv[2]);
		style = atoi_cust(argv[3]);
		if (style < 1 | style > 5)
		{
			write(1, "Invalid style. Should be between 1 and 5.\n", 42);
		}
		else
		{
			rush(n_cols, n_rows, style);
		}
	}
}
