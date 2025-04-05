#include "fractol.h"

int julia(t_fractol *f, double z_re, double z_im)
{
    int i;
    double temp;
    
    i = 0;
    while (z_re * z_re + z_im * z_im <= 4 && i < (f->max_iters - 1)) {
        temp = z_re * z_re - z_im * z_im + f->kr;
        z_im = 2 * z_re * z_im + f->ki;
        z_re = temp;
        i++;
    }
    return (i);
}

int mandelbrot(t_fractol *f, double c_re, double c_im)
{
    int i;
    double  z_re;
    double  z_im;
    double  temp;

    z_re = 0;
    z_im = 0;
    i = 0;
    while (z_re * z_re + z_im * z_im <= 4 && i < (f->max_iters - 1)) {
        temp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = temp;
        i++;
    }
    return (i);
}

int burning_ship(t_fractol *f, double c_re, double c_im)
{
    int i;
    double  z_re;
    double  z_im;
    double  temp;
    c_im = -c_im;

    z_re = 0;
    z_im = 0;
    i = 0;
    while (z_re * z_re + z_im * z_im <= 4 && i < (f->max_iters - 1)) {
        temp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * fabs(z_re) * fabs(z_im) + c_im;
        z_re = temp;

        i++;
    }
    return (i);
}

void    newton_calcs(double z_re, double z_im, double *diff_re, double *diff_im)
{
    double  f_re;
    double  f_im;
    double  df_re;
    double  df_im;

    f_re = z_re * ((z_re * z_re) - 3 * (z_im * z_im)) - 1;
    f_im = z_im * (3 * (z_re * z_re) - (z_im * z_im));
    df_re = 3 * ((z_re * z_re) - (z_im * z_im));
    df_im = 6 * z_re * z_im;
    *diff_re = (f_re * df_re + f_im * df_im) / (df_re * df_re + df_im * df_im);
    *diff_im = (f_im * df_re - f_re * df_im) / (df_re * df_re + df_im * df_im);
}

int newton(t_fractol *f, double z_re, double z_im)
{
    int i;
    double  temp_re;
    double  temp_im;
    double diff_re;
    double diff_im;

    i = 0;
    while (i < (f->max_iters - 1))
    {
        newton_calcs(z_re, z_im, &diff_re, &diff_im);
        temp_re = z_re - diff_re;
        temp_im = z_im - diff_im;
        if ((diff_re * diff_re + diff_im * diff_im) < 1e-6)
            break;
        z_re = temp_re;
        z_im = temp_im;
        i++;
    }
    return (i);
}