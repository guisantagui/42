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