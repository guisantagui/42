/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:37:38 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/11 22:46:19 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int	mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(f, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(f, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(f, (double)x / WIDTH, 'R');
		if (y < 0)
			move(f, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (f, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(f, 2);
	else if (keycode == MOUSE_LEFT_CLICK)
	{
		if (f->set == 1)
			julia_shift(x, y, f);
	}
	init_palette(f);
	render(f);
	return (0);
}

static void	reset_constants(t_fractol *f)
{
	if (f->set == 1)
	{
		set_bounds(f, -2.0, 2.0, 0);
		f->kr = -0.8;
		f->ki = 0.156;
	}
	else if (f->set == 2)
		set_bounds(f, -4.0, 4.0, 0);
	else if (f->set == 3)
		set_bounds(f, -3.0, 3.0, 0);
	else if (f->set == 4)
		set_bounds(f, -2000.0, 2000.0, 0);
	else if (f->set == 5)
		set_bounds(f, -1., 1., PI);
	f->max_iters = MAX_ITER;
	init_palette(f);
	f->zoom = ZOOM;
}

int	key_event_set_set(int keycode, t_fractol *f)
{
	if (keycode == KEY_ONE && f->set != 1)
		f->set = 1;
	else if (keycode == KEY_TWO && f->set != 2)
		f->set = 2;
	else if (keycode == KEY_THREE && f->set != 3)
		f->set = 3;
	else if (keycode == KEY_FOUR && f->set != 4)
		f->set = 4;
	else if (keycode == KEY_FIVE && f->set != 5)
		f->set = 5;
	else
		return (1);
	reset_constants(f);
	render (f);
	return (0);
}

int	exit_hook(t_fractol *fractol)
{
	ft_printf("Exiting program...\n");
	free_fractol(fractol);
	exit(0);
	return (0);
}

int	key_event(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		exit_hook(f);
	else if (keycode == KEY_PLUS)
		zoom(f, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(f, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(f, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(f, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(f, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(f, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		shift_cols(f);
	else if (!key_event_set_set(keycode, f))
		return (1);
	else
		return (1);
	init_palette(f);
	render(f);
	return (0);
}
