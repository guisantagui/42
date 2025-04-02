#include "fractol.h"

void    free_fractol(t_fractol *f)
{
    if (f != NULL)
    {
        if (f->palette != NULL)
            free(f->palette);
        if (f->color != NULL)
            free(f->color);
        if (f->win != NULL)
            mlx_destroy_window(f->mlx, f->win);
        if (f->img != NULL)
        {
            //if (f->img->addr != NULL)
            //    free(f->img->addr);
            if (f->img->img != NULL)
                mlx_destroy_image(f->mlx, f->img->img);
        }
        free(f);
    }
}

void    free_exit(t_fractol *f)
{
    free_fractol(f);
    ft_printf("Error\n");
    exit(1);
}