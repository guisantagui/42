#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol   *fractol;

    fractol = malloc(sizeof(t_fractol));
    printf("Hola");
    init_zero(fractol);
    parse_args(fractol, argc, argv);
    init(fractol);
    render(fractol);
    mlx_hook(fractol->win, 17, 0, exit_hook, fractol);
    mlx_mouse_hook(fractol->win, mouse_event, fractol);
    mlx_loop(fractol->mlx);
    return (0);
}