#include "fractol.h"

static int    get_fractal(t_fractol *f, double re, double im)
{
    int	n_iters;

    if (ft_strncmp(f->set, "JULIA", ft_strlen(f->set)) == 0)
        n_iters = julia(f, re, im);
    else
        n_iters = 0;
    return (n_iters);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
    int max_iter = MAX_ITER;

    mlx_clear_window(f->mlx, f->win);
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++)
        {
            real = f->r_min + x * (f->r_max - f->r_min)/WIDTH;
            imag = f->i_max - y * (f->i_min - f->i_max)/HEIGHT;
            
            int iterations = get_fractal(f, real, imag);
            if (iterations == max_iter)
                color = create_trgb(0, 0, 0, 0); // Black if inside Julia set
            else
                color = create_trgb(0, iterations % 256, iterations % 64, iterations % 128); // Color based on iterations
            //ft_printf("%d\n", color);
            // Put pixel in image
            my_mlx_pixel_put(f->img, x, y, color);
        }
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}