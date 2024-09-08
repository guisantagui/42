/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:23 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/08 17:27:05 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row_1(int n_col, int is_top_end)
{
	int	j;

	j = 0;
	while (j < n_col)
	{
		if (is_top_end == 0)
		{
			if (j == 0 | j == n_col - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		else
		{
			if (j == 0 | j == n_col -1)
				ft_putchar('o');
			else
				ft_putchar('-');
		}
		j++;
	}
	ft_putchar('\n');
}

void	rush00(int x, int y)
{
	int	i;

	if (x >= 0 && y >= 0)
	{
		i = 0;
		while (i < y)
		{
			if (i == 0 | i == y - 1)
				print_row_1(x, 1);
			else
				print_row_1(x, 0);
			i++;
		}
	}
}
