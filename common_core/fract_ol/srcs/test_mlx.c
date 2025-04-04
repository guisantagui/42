#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol   *fractol;

    if (argc > 1)
    {
        fractol = malloc(sizeof(t_fractol));
        if (!fractol)
            free_exit(fractol);
        init_zero(fractol);
        parse_args(fractol, argc, argv);
        init(fractol);
        printf("i_min: %f\n", fractol->i_min);
        printf("i_max: %f\n", fractol->i_max);
        printf("r_min: %f\n", fractol->r_min);
        printf("r_max: %f\n", fractol->r_max);
        printf("color: %X\n", fractol->color[0]);
        printf("N colors: %d\n", fractol->n_cols);
        printf("N colors: %X\n", fractol->palette[14]);
        printf("Set: %d\n", fractol->set);
        render(fractol);
        mlx_hook(fractol->win, 17, 0, exit_hook, fractol);
        mlx_mouse_hook(fractol->win, mouse_event, fractol);
        mlx_key_hook(fractol->win, key_event, fractol);
        mlx_loop(fractol->mlx);
    }
    return (0);
}