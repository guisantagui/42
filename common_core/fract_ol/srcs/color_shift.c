#include "fractol.h"

int color_shift_hue(int color, double hue_shift)
{
    int *col_trgb;
    double col_hsv[3];
    int i;
    double min;
    double max;
    double delta;
    double h;
    double s;
    double v;
    int shift_col;

    col_trgb = get_trgb(color);
    i = 0;
    while (i < 3)
    {
        col_hsv[i] = (double)(col_trgb[i] & 0xFF) / 255.0;
        i++;
    }
    max = fmax(col_hsv[0], fmax(col_hsv[1], col_hsv[2]));
    min = fmin(col_hsv[0], fmin(col_hsv[1], col_hsv[2]));
    delta = max - min;

    if (max == 0)
        s = 0;
    else
        s = delta / max;

    v = max;

    if (delta < 0.00001) {
        h = 0.0;
    } else if (max == col_hsv[2]) {
        h = (col_hsv[1] - col_hsv[0]) / delta;  // Red is max
    } else if (max == col_hsv[1]) {
        h = 2.0 + (col_hsv[0] - col_hsv[2]) / delta;  // Green is max
    } else {
        h = 4.0 + (col_hsv[2] - col_hsv[1]) / delta;  // Blue is max
    }
    h = fmod(h + hue_shift, 6.0);
    if (h < 0)
        h += 6.0;
    double p, q, t, f;
    
    if (s == 0)
        col_hsv[2] = col_hsv[1] = col_hsv[0] = v;
    else
    {
        i = (int)h;
        f = h - i;
        p = v * (1.0 - s);
        q = v * (1.0 - s * f);
        t = v * (1.0 - s * (1.0 - f));
        switch (i) {
            case 0: col_hsv[2] = v; col_hsv[1] = t; col_hsv[0] = p; break;
            case 1: col_hsv[2] = q; col_hsv[1] = v; col_hsv[0] = p; break;
            case 2: col_hsv[2] = p; col_hsv[1] = v; col_hsv[0] = t; break;
            case 3: col_hsv[2] = p; col_hsv[1] = q; col_hsv[0] = v; break;
            case 4: col_hsv[2] = t; col_hsv[1] = p; col_hsv[0] = v; break;
            case 5: col_hsv[2] = v; col_hsv[1] = p; col_hsv[0] = q; break;
        }
    }
    shift_col = create_trgb(col_trgb[3], (int)(col_hsv[2] * 255), (int)(col_hsv[1] * 255), (int)(col_hsv[0] * 255));
    free(col_trgb);
    return (shift_col);
}

void shift_cols(t_fractol *f)
{
    int i;

    i = 0;
    while (i < f->n_cols)
    {
        f->color[i] = color_shift_hue(f->color[i], 1);
        i++;
    }
}