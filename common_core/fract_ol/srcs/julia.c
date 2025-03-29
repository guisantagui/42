#include "fractol.h"

int julia(t_fractol *f, double z_re, double z_im)
{
    int i;
    double temp;
    
    i = 0;
    while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER) {
        temp = z_re * z_re - z_im * z_im + f->kr;
        z_re = temp;
        z_im = 2 * z_re * z_im + f->ki;
        i++;
    }
    return (i);
}