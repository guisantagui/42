#include "fractol.h"

void    zoom(t_fractol *f, double zoom)
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