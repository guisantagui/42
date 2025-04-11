/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:08:49 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/11 23:20:52 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_fractal(t_fractol *f, double re, double im)
{
	int	n_iters;

	if (f->set == 1)
		n_iters = julia(f, re, im);
	else if (f->set == 2)
		n_iters = mandelbrot(f, re, im);
	else if (f->set == 3)
		n_iters = burning_ship(f, re, im);
	else if (f->set == 4)
		n_iters = newton(f, re, im, "three");
	else if (f->set == 5)
		n_iters = newton(f, re, im, "cosh");
	else if (f->set == 6)
		n_iters = newton(f, re, im, "sun");
	else
		n_iters = 0;
	return (n_iters);
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_iterations(t_fractol *f, int x, int y)
{
	double	real;
	double	imag;
	int		iterations;

	real = f->r_min + (double)x * (f->r_max - f->r_min) / WIDTH;
	imag = f->i_max + (double)y * (f->i_min - f->i_max) / HEIGHT;
	iterations = get_fractal(f, real, imag);
	return (iterations);
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	int		color;
	int		iterations;

	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iterations = get_iterations(f, x, y);
			color = f->palette[iterations];
			my_mlx_pixel_put(f->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}
