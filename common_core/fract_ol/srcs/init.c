#include "fractol.h"

void    init_zero(t_fractol *f)
{
    double  center;
    double  ar;
    double  range;

    f->kr = 0;
    f->ki = 0;
    f->r_min = -2;
    f->r_max = 2;
    center = (f->r_min + f->r_max) / 2.0;
    ar = (double)WIDTH / (double)HEIGHT;
    range = (f->r_max - f->r_min);
    f->i_max = center + range / 2.0 / ar;
    f->i_min = center - range / 2.0 / ar;
    f->set = 0;
    f->zoom = ZOOM;
    f->max_iters = MAX_ITER;
    f->palette = NULL;
}

void    init_mlx(t_fractol *f)
{
    f->mlx = mlx_init();
    if (!f->mlx)
    {
        exit(1);
    }
    f->img = malloc(sizeof(t_data));
    if (!f->img)
    {
        exit(1);
    }
    f->img->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    if (!f->img->img)
    {
        exit(1);
    }
    f->img->addr = mlx_get_data_addr(f->img->img,
        &f->img->bits_per_pixel,
        &f->img->line_length,
        &f->img->endian);
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
    if (!f->win)
        exit(1);
}

void    get_palette_monochrome(t_fractol *f)
{
    int col1;
    int col2;
    int i;
    int j;
    double fraction;

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

void    get_palette_multichrome(t_fractol *f)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < f->max_iters)
	{
		j = 0;
		while ((i + j) < f->max_iters && j < (f->max_iters / (f->n_cols - 1)))
		{
			fraction = (double)j / (f->max_iters / (f->n_cols - 1));
			f->palette[i + j] = interpol_cols(f->color[x], f->color[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	f->palette[f->max_iters - 1] = 0;
}

void    init_palette(t_fractol *f)
{
    if (f->palette != NULL)
        free(f->palette);
    f->palette = malloc(sizeof(int) * f->max_iters);
    if (!f->palette)
        exit(1);
    if (f->n_cols == 1)
        get_palette_monochrome(f);
    else
        get_palette_multichrome(f);
}

void    init(t_fractol *f)
{
    init_palette(f);
    init_mlx(f);
}