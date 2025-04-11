/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:47:56 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/11 20:52:46 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_atox_aux(char *str, char *digits, int *i, int *n_digs)
{
	int	res;
	int	j;

	res = 0;
	while (str[*i] && ft_strchr(digits, (int)str[*i]) != NULL)
	{
		j = 0;
		res *= 16;
		while (digits[j])
		{
			if (ft_toupper(str[*i]) == digits[j])
			{
				res += j;
				break ;
			}
			j++;
		}
		(*i)++;
		(*n_digs)++;
	}
	return (res);
}

static int	ft_atox(char *str)
{
	int		res;
	char	digits[17];
	int		i;
	int		n_digs;

	ft_strlcpy(digits, "0123456789ABCDEF", 17);
	i = skip_spaces(str);
	n_digs = 0;
	res = ft_atox_aux(str, digits, &i, &n_digs);
	if (n_digs == 6 && str[i] == '\0')
		return (res);
	else
		return (-42);
}

void	set_color(t_fractol *f, int i_o, int argc, char **argv)
{
	int	i;
	int	col;

	i = i_o;
	f->color = malloc(sizeof(int) * (argc - i_o));
	if (!f->color)
		free_exit(f);
	f->n_cols = argc - i_o;
	while (i < argc)
	{
		col = ft_atox(argv[i]);
		if (col < 0)
			free_exit(f);
		f->color[i - i_o] = col;
		i++;
	}
}
