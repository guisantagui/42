#include "fractol.h"

double *norm_trgb(int color)
{
    int *col_trgb;
    double  *col_hsv;
    int i;

    col_trgb = get_trgb(color);
    if (!col_trgb)
        return (NULL);
    col_hsv = malloc(sizeof(double) * 3);
    if (!col_hsv)
    {
        free (col_trgb);
        return (NULL);
    }
    i = 0;
    while (i < 3)
    {
        col_hsv[i] = (double)(col_trgb[i] & 0xFF) / 255.0;
        i++;
    }
    free(col_trgb);
    return (col_hsv);
}

double  *get_hsv(double *norm_rgb)
{
    double  *hsv;
    double  min;
    double  max;

    max = fmax(norm_rgb[0], fmax(norm_rgb[1], norm_rgb[2]));
    min = fmin(norm_rgb[0], fmin(norm_rgb[1], norm_rgb[2]));
    hsv = malloc(sizeof(double) * 3);
    if (!hsv)
        return (NULL);
    if (max == 0)
        hsv[1] = 0;
    else
        hsv[1] = (max - min) / max;
    hsv[2] = max;
    if ((max - min) < 0.00001)
        hsv[0] = 0.0;
    else if (max == norm_rgb[2])
        hsv[0] = (norm_rgb[1] - norm_rgb[0]) / (max - min);
    else if (max == norm_rgb[1])
        hsv[0] = 2.0 + (norm_rgb[0] - norm_rgb[2]) / (max - min);
    else
        hsv[0] = 4.0 + (norm_rgb[2] - norm_rgb[1]) / (max - min);
    return (hsv);
}

void set_rgb(double *rgb, double r, double g, double b)
{
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
}

double *get_ifpqt(double *hsv)
{
    double  *ifpqt;

    ifpqt = malloc(sizeof(double) * 5);
    if (!ifpqt)
        return (NULL);
    ifpqt[0] = trunc(hsv[0]);
    ifpqt[1] = hsv[0] - ifpqt[0];
    ifpqt[2] = hsv[2] * (1.0 - hsv[1]);
    ifpqt[3] = hsv[2] * (1.0 - hsv[1] * ifpqt[1]);
    ifpqt[4] = hsv[2] * (1.0 - hsv[1] * (1.0 - ifpqt[1]));
    return (ifpqt);
}

void    set_rgb_hsv_ifpqt(double *norm_rgb, double *ifpqt, double *hsv)
{
    if (ifpqt[0] == 0)
        set_rgb(norm_rgb, ifpqt[2], ifpqt[4], hsv[2]);
    else if (ifpqt[0] == 1.0)
        set_rgb(norm_rgb, ifpqt[2], hsv[2], ifpqt[3]);
    else if (ifpqt[0] == 2.0)
        set_rgb(norm_rgb, ifpqt[4], hsv[2], ifpqt[2]);
    else if (ifpqt[0] == 3.0)
        set_rgb(norm_rgb, hsv[2], ifpqt[3], ifpqt[2]);
    else if (ifpqt[0] == 4.0)
        set_rgb(norm_rgb, hsv[2], ifpqt[2], ifpqt[4]);
    else if (ifpqt[0] == 5.0)
        set_rgb(norm_rgb, ifpqt[3], ifpqt[2], hsv[2]);
}