/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:47:01 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/14 18:49:10 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_shift(int x, int y, t_fractol *f)
{
	f->kr = f->r_min + (double)x * (f->r_max - f->r_min) / WIDTH;
	f->ki = f->i_max + (double)y * (f->i_min - f->r_max) / HEIGHT;
	render(f);
	return (0);
}

int	julia(t_fractol *f, double z_re, double z_im)
{
	int		i;
	double	temp;

	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < (f->max_iters - 1))
	{
		temp = z_re * z_re - z_im * z_im + f->kr;
		z_im = 2 * z_re * z_im + f->ki;
		z_re = temp;
		i++;
	}
	return (i);
}
