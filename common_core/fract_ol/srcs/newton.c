#include "fractol.h"

static void    newton_calcs_three(double z_re, double z_im, double *diff_re, double *diff_im)
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

static void newton_calcs_cosh(double z_re, double z_im, double *diff_re, double *diff_im)
{
    double  f_re;
    double  f_im;
    double  df_re;
    double  df_im;
    double denominator;

    f_re = cosh(z_re) * cos(z_im) - 1;
    f_im = sinh(z_re) * sin(z_im);
    df_re = sinh(z_re) * cos(z_im);
    df_im = cosh(z_re) * sin(z_im);
    denominator = df_re * df_re + df_im * df_im;
    *diff_re = (f_re * df_re + f_im * df_im) / denominator;
    *diff_im = (f_im * df_re - f_re * df_im) / denominator;
}

int newton(t_fractol *f, double z_re, double z_im, char *which)
{
    int i;
    double  temp_re;
    double  temp_im;
    double diff_re;
    double diff_im;

    i = 0;
    while (i < (f->max_iters - 1))
    {
        if (ft_strncmp(which, "three", ft_strlen(which)) == 0)
            newton_calcs_three(z_re, z_im, &diff_re, &diff_im);
        else if (ft_strncmp(which, "cosh", ft_strlen(which)) == 0)
            newton_calcs_cosh(z_re, z_im, &diff_re, &diff_im);
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