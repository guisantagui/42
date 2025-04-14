/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:54:37 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/14 18:49:58 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_palette_monochrome(t_fractol *f)
{
	int		col1;
	int		col2;
	int		i;
	int		j;
	double	fraction;

	col1 = 0x000000;
	col2 = f->color[0];
	i = 0;
	while (i < f->max_iters)
	{
		j = 0;
		while (j < f->max_iters / 2)
		{
			fraction = (double)j / (f->max_iters / 2);
			f->palette[i + j] = interpol_cols(col1, col2, fraction);
			j++;
		}
		col1 = col2;
		col2 = 0xFFFFFF;
		i += j;
	}
	f->palette[f->max_iters - 1] = 0;
}

static void	get_palette_multichrome(t_fractol *f)
{
	int		i;
	int		j;
	int		x;
	double	fraction;
	int		seg_size;

	i = 0;
	x = 0;
	seg_size = f->max_iters / (f->n_cols - 1);
	while (i < f->max_iters && x < (f->n_cols - 1))
	{
		j = 0;
		while ((i + j) < f->max_iters && j < seg_size)
		{
			fraction = (double)j / seg_size;
			f->palette[i + j] = interpol_cols(f->color[x],
					f->color[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	f->palette[f->max_iters - 1] = 0;
}

void	init_palette(t_fractol *f)
{
	if (f->palette != NULL)
		free(f->palette);
	f->palette = malloc(sizeof(int) * f->max_iters);
	if (!f->palette)
		free_exit(f);
	if (f->n_cols == 1)
		get_palette_monochrome(f);
	else
		get_palette_multichrome(f);
}
