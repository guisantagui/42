/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:26:38 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/08 17:04:13 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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

void	rush(int x, int y)
{
	int	i;

	if (x >= 0 && y >= 0)
	{
		i = 0;
		while (i < y)
		{
			if (i == 0 | i == y - 1)
				print_row(x, 1);
			else
				print_row(x, 0);
			i++;
		}
	}
}
