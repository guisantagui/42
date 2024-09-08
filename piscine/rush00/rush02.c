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

void	print_row_3(int n_col, char v, char m)
{
	int     j;

	j = 0;
	while (j < n_col)
	{
		if (j == 0 | j == n_col - 1)
			ft_putchar(v);
		else
			ft_putchar(m);
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
				print_row_3(x, 'A', 'B');
			else if (i == y - 1)
				print_row_3(x, 'C', 'B');
			else
				print_row_3(x, 'B', ' ');
			i++;
		}
	}
}
