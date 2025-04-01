#include "fractol.h"

#define PI 3.141592653589793

/*
void    do_cycles(t_data *img, int color, int cycles)
{
    int x;
    int y;
    int nu_col;
    double  shade_1;
    double  shade_2;
    int r, g, b, t;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            t = get_t(color);
            r = get_r(color);
            g = get_g(color);
            b = get_b(color);

            r = (int)((double)x * ((double)255 / WIDTH));
            g = (int)((double)y * ((double)255 / HEIGHT));
            
            shade_1 = (sin((double)x/(((double)WIDTH/360) / cycles) * PI/180) + 1)/ 2;
            shade_2 = (sin((double)y/(((double)WIDTH/360) / cycles) * PI/180) + 1)/ 2;
            b = (int)(b - (255 * shade_1));
            nu_col = create_trgb(t, r, g, b);
            //printf("B: %d\n", b);
            nu_col = add_shade(nu_col, shade_1 * shade_2);
            my_mlx_pixel_put(img, x, y, nu_col);
            x++;
        }
        y++;
    }
}
*/
int main(int argc, char **argv)
{
    t_fractol   *fractol;

    fractol = malloc(sizeof(t_fractol));
    init_zero(fractol);
    parse_args(fractol, argc, argv);
    init(fractol);
    printf("kr: %f\n", fractol->kr);
    printf("ki: %f\n", fractol->ki);
    printf("col: %i\n", fractol->color[0]);
    render(fractol);
    mlx_mouse_hook(fractol->win, mouse_event, fractol);
    mlx_loop(fractol->mlx);
    return (0);
}