/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:51:21 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/09 20:54:23 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_zero(t_fractol *f)
{
	f->mlx = NULL;
	f->img = NULL;
	f->win = NULL;
	f->kr = 0;
	f->ki = 0;
	f->r_min = 0;
	f->r_max = 0;
	f->i_max = 0;
	f->i_min = 0;
	f->set = 0;
	f->zoom = ZOOM;
	f->max_iters = MAX_ITER;
	f->palette = NULL;
}

static void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		free_exit(f);
	f->img = malloc(sizeof(t_data));
	if (!f->img)
		free_exit(f);
	f->img->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img->img)
		free_exit(f);
	f->img->addr = mlx_get_data_addr(f->img->img,
			&f->img->bits_per_pixel,
			&f->img->line_length,
			&f->img->endian);
	if (!f->img->addr)
		free_exit(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!f->win)
		free_exit(f);
}

void	init(t_fractol *f)
{
	init_palette(f);
	init_mlx(f);
}
