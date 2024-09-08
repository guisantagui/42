/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:11:56 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/08 17:23:49 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row_3(int n_col, int is_top, int is_end)
{
	int     j;

	j = 0;
	while (j < n_col)
	{
		if (is_top == 0 && is_end == 0)
		{
			if (j == 0 | j == n_col - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		else if (is_top == 1)
		{
			if (j == 0 | j == n_col - 1)
				ft_putchar('A');
			else
				ft_putchar('B');
		}
		else if (is_end == 1)
			if (j == 0 | j == n_col - 1)
				ft_putchar('C');
			else
				ft_putchar('B');
		j++;
	}
	ft_putchar('\n');
}

void	rush02(int x, int y)
{
	int     i;

	if (x >= 0 && y >= 0)
	{
		i = 0;
		while (i < y)
		{
			if (i == 0)
				print_row_3(x, 1, 0);
			else if (i == y - 1)
				print_row_3(x, 0, 1);
			else
				print_row_3(x, 0, 0);
			i++;
		}
	}
}
