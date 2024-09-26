/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:56:58 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/26 19:57:41 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int	has_char(char *str)
{
	int	i;
	char	c;

	i = 0;
	c = 'H';
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main()
{
	char *tab[6];
	tab[0] = strdup("Hola");
	tab[1] = strdup("adios");
	tab[2] = strdup("quetal");
	tab[3] = strdup("quepasa");
	tab[4] = strdup("aquiestamos");
	tab[5] = 0;
	printf("%d\n", ft_any(tab, has_char));
}
*/