#include "fractol.h"

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