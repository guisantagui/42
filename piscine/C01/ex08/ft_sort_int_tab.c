/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:37:35 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/05 18:38:27 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	t;
	int	n_changes;

	n_changes = 1;
	while (n_changes != 0)
	{
		i = 0;
		n_changes = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				t = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = t;
				n_changes++;
			}
			i++;
		}
	}
}
