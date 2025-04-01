#include "fractol.h"


static int    get_fractal(t_fractol *f, double re, double im)
{
    int	n_iters;

    if (f->set == 1)
        n_iters = julia(f, re, im);
    else
        n_iters = 0;
    return (n_iters);
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void render(t_fractol *f)
{
    int x;
    int y;
    double real, imag;
    int color;

    //mlx_clear_window(f->mlx, f->win);
    for (y = -1; y < HEIGHT; y++) {
        for (x = -1; x < WIDTH; x++)
        {
            real = f->r_min + (double)x * (f->r_max - f->r_min)/WIDTH;
            imag = f->i_max + (double)y * (f->i_min - f->i_max)/HEIGHT;
            int iterations = get_fractal(f, real, imag);
            color = f->palette[iterations];
            my_mlx_pixel_put(f->img, x, y, color);
        }
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}