#include "fractol.h"

void    init_mlx(t_fractol *fractol)
{
    fractol->mlx = mlx_init();
    if (!fractol->mlx)
    {
        exit(1);
    }
    fractol->img = malloc(sizeof(t_data));
    if (!fractol->img)
    {
        exit(1);
    }
    fractol->img->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    if (!fractol->img->img)
    {
        exit(1);
    }
    fractol->img->addr = mlx_get_data_addr(fractol->img->img,
        &fractol->img->bits_per_pixel,
        &fractol->img->line_length,
        &fractol->img->endian);
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract-ol");
    if (!fractol->win)
        exit(1);
    fractol->r_min = -2;
    fractol->r_max = 2;
    fractol->i_min = -2;
    fractol->i_max =  fractol->i_min + (fractol->r_max - fractol->r_min) * HEIGHT / WIDTH;
    fractol->set = "JULIA";
}