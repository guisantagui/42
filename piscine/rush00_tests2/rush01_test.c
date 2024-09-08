/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:28:27 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/08 18:04:43 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row_2(int n_col, int row_idx, int n_row)
{
	int	j;
	char	v1;
	char	v2;
	char	mid;

	j = 0;
	while (j < n_col)
	{
		if ((row_idx == 0 && j == 0) | (row_idx == n_row - 1 && j == n_col - 1)) 
			ft_putchar('/');
		else if (row_idx < n_row - 1 && row_idx > 0 & j < n_col - 1 && j > 0)
			ft_putchar(' ');
		else if (j == 0 | j == n_col - 1 && row_idx != 0 && row_idx != n_row - 1)
			ft_putchar('*');
		else if (row_idx == 0 | row_idx == n_row - 1 && j != 0 && j != n_col - 1)
			ft_putchar('*');
		else
			ft_putchar('\\');
		j++;
	}
	ft_putchar('\n');
}

void	rush01(int x, int y)
{
	int	i;

	if (x >= 0 && y >= 0)
	{
		i = 0;
		while (i < y)
		{
			print_row_2(x, i, y);
			i++;
		}
	}
}
