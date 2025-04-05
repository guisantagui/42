#include "fractol.h"

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