#include "fractol.h"

static void    set_julia_cnstnts(t_fractol *f, char **argv)
{
    f->kr = ft_atod(argv[2]);
    f->ki = ft_atod(argv[3]);
    if (f->kr < -2)
        f->kr = -2;
    else if (f->kr > 2)
        f->kr = 2;
    if (f->ki < -2)
        f->ki = -2;
    else if (f->ki > 2)
        f->ki = 2;
}

static void    set_bounds(t_fractol *f, double min, double max)
{
    double  center;
    double  ar;
    double range;

    f->r_min = min;
    f->r_max = max;
    center = (f->r_min + f->r_max) / 2;
    ar = (double)WIDTH / (double)HEIGHT;
    range = (f->r_max - f->r_min);
    f->i_max = center + range / 2 / ar;
    f->i_min = center - range / 2 / ar;
}

static void    set_constants(t_fractol *f, char **argv)
{
    if (f->set == 1)
    {
        set_bounds(f, -2.0, 2.0);
        set_julia_cnstnts(f, argv);
    }
    else if (f->set == 2)
        set_bounds(f, -4.0, 4.0);
    else if (f->set == 3)
        set_bounds(f, -3.0, 3.0);
    else if (f->set == 4)
        set_bounds(f, -2000.0, 2000.0);
}

static void    fractol_setup(t_fractol *f, int argc, char **argv)
{
    int i_o;

    if (f->set == 1)
        i_o = 4;
    else
        i_o = 2;
    if (argc < i_o)
        free_exit(f);
    if (argc > i_o)
    {
        set_constants(f, argv);
        set_color(f, i_o, argc, argv);
    }
    else if (argc == i_o)
    {
        set_constants(f, argv);
        f->color = malloc(sizeof(int));
        if (!f->color)
            free_exit(f);
        f->color[0] = 0xFFFFFF;
        f->n_cols = 1;
    }
}

void    parse_args(t_fractol *f, int argc, char **argv)
{
    get_set(f, argv);
    fractol_setup(f, argc, argv);
}