/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:54:28 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/11 22:56:11 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->r_max - f->r_min;
	center_i = f->i_max - f->i_min;
	f->r_min = f->r_min + (center_r - zoom * center_r) / 2;
	f->r_max = f->r_max - (center_r - zoom * center_r) / 2;
	f->i_min = f->i_min + (center_i - zoom * center_i) / 2;
	f->i_max = f->i_max - (center_i - zoom * center_i) / 2;
	f->zoom *= zoom;
	f->max_iters = MAX_ITER - 10 * log2(f->zoom);
	if (f->max_iters < MAX_ITER)
		f->max_iters = MAX_ITER;
}

void	move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->r_max - f->r_min;
	center_i = f->i_max - f->i_min;
	if (direction == 'R')
	{
		f->r_min += center_r * distance;
		f->r_max += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->r_min -= center_r * distance;
		f->r_max -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->i_min -= center_i * distance;
		f->i_max -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->i_min += center_i * distance;
		f->i_max += center_i * distance;
	}
}
