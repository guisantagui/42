#include "fractol.h"

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int add_shade(int color, double shade)
{
    int t;
    int r;
    int g;
    int b;

    t = get_t(color);
    r = get_r(color) * shade;
    g = get_g(color) * shade;
    b = get_b(color) * shade;
    return (create_trgb(t, r, g, b));
}

int *get_trgb(int color)
{
    int *col;

    col = malloc(sizeof(int) * 4);
    if (!col)
        return (NULL);
    col[0] = get_b(color);
    col[1] = get_g(color);
    col[2] = get_r(color);
    col[3] = get_t(color);
    return (col);
}

int interpol_cols(int col_1, int col_2, double fraction)
{
    int result;
    int *col_1_trgb;
    int *col_2_trgb;
    int col_interp[4];
    int i;

    col_1_trgb = get_trgb(col_1);
    col_2_trgb = get_trgb(col_2);
    i = 0;
    while (i < 4)
    {
        col_interp[i] = col_1_trgb[i] + (col_2_trgb[i] - col_1_trgb[i]) * fraction;
        i++;
    }
    result = create_trgb(col_interp[3], col_interp[2], col_interp[1], col_interp[0]);
    free(col_1_trgb);
    free(col_2_trgb);
    return (result);
}

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