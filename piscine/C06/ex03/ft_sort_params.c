/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:27:03 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/18 18:51:30 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_str_tab(char **tab, int size)
{
	int		i;
	char	*t;
	int		n_changes;

	n_changes = 1;
	while (n_changes != 0)
	{
		i = 0;
		n_changes = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_str_tab(argv + i, argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
