/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:28:27 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/08 18:17:15 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char[]	get_row_chars(int  row_idx, int n_row)
{
	char arr_chars[3];

	if (row_idx == 0)
	{
		arr_chars[0] = '/';
		arr_chars[1] = '\\';
		arr_chars[2] = '*';
	}
	else if (row_idx == n_row - 1)
	{
		arr_chars[0] = '\\';
		arr_chars[1] = '/';
		arr_chars[2] = '*';
	}
	else
	{
		arr_chars[1] = '*';
		arr_chars[2] = '*';
		arr_chars[3] = ' ';
	}
}

void	print_row_2(int n_col, int row_idx, int n_row)
{
	int	j;
	char	chars[3];

	chars = get_row_chars(row_idx, n_row)
	j = 0;
	while (j < n_col)
	{
		if (j == 0)
			ft_putchar(chars[0]);
		else if (j == n_col - 1)
			ft_putchar(chars[1]);
		else
			ft_putchar(chars[3]);
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
			print_row_2(x, i, n_row);
			i++;
		}
	}
}
