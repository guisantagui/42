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

void	print_row_2(int n_col, char v1, char v2, char m)
{
	int	j;

	j = 0;
	while (j < n_col)
	{
		if (j == 0)
			ft_putchar(v1);
		else if (j == n_col - 1)
			ft_putchar(v2);
		else
			ft_putchar(m);
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
			if (i == 0)
				print_row_2(x, '/', '\\', '*');
			else if (i == y - 1)
				print_row_2(x, '\\', '/', '*');
			else
				print_row_2(x, '*', '*', ' ');
			i++;
		}
	}
}
