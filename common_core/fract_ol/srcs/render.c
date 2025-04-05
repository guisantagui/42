#include "fractol.h"


static int    get_fractal(t_fractol *f, double re, double im)
{
    int	n_iters;

    if (f->set == 1)
        n_iters = julia(f, re, im);
    else if (f->set == 2)
        n_iters = mandelbrot(f, re, im);
    else if (f->set == 3)
        n_iters = burning_ship(f, re, im);
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

void    print_colors(t_fractol *f)
{
    int i;

    i = 0;
    ft_printf("Colors:\n");
    while (i < f->n_cols)
    {
        ft_printf("%X\n", f->color[i]);
        i++;
    }
}

void    print_palette(t_fractol *f)
{
    int i;

    i = 0;
    ft_printf("Palette:\n");
    while (i < f->max_iters)
    {
        ft_printf("%X\n", f->palette[i]);
        i++;
    }
}

void render(t_fractol *f)
{
    int x;
    int y;
    double real, imag;
    int color;

    mlx_clear_window(f->mlx, f->win);
    y = 0;
    while (y < HEIGHT) {
        x = 0;
        while (x < WIDTH)
        {
            real = f->r_min + (double)x * (f->r_max - f->r_min)/WIDTH;
            imag = f->i_max + (double)y * (f->i_min - f->i_max)/HEIGHT;
            int iterations = get_fractal(f, real, imag);
            //ft_printf("%d\n", iterations);
            color = f->palette[iterations];
            my_mlx_pixel_put(f->img, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}