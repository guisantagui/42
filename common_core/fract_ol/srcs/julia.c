#include "fractol.h"

int julia(t_fractol *f, double z_re, double z_im)
{
    int i;
    double temp;
    
    i = 0;
    while (z_re * z_re + z_im * z_im <= 4 && i < f->max_iters) {
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
    while (z_re * z_re + z_im * z_im <= 4 && i < f->max_iters) {
        temp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = temp;
        i++;
    }
    return (i);
}
/*
int julia(double kr, double ki, double z_re, double z_im)
{
    int i;
    double temp;
    
    i = 0;
    while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER) {
        temp = z_re * z_re - z_im * z_im + kr;
        z_im = 2 * z_re * z_im + ki;
        z_re = temp;
        i++;
    }
    return (i);
}
*/