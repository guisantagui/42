#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol   *fractol;

    if (argc > 1)
    {
        fractol = malloc(sizeof(t_fractol));
        if (!fractol)
        {
            ft_printf("Error\n");
            exit (1);
        }
        init_zero(fractol);
	ft_printf("Hola\n");
        parse_args(fractol, argc, argv);
	ft_printf("set: %d\n", fractol->set);
	printf("r_min: %f\n", fractol->r_min);
	printf("r_max: %f\n", fractol->r_max);
	printf("i_min: %f\n", fractol->i_min);
	printf("i_max: %f\n", fractol->i_max);
	printf("color: %X\n", *(fractol->color));
        init(fractol);
	printf("HELE\n");
        render(fractol);
        mlx_hook(fractol->win, 17, 0, exit_hook, fractol);
        mlx_mouse_hook(fractol->win, mouse_event, fractol);
        mlx_key_hook(fractol->win, key_event, fractol);
        mlx_loop(fractol->mlx);
    }
    return (0);
}
