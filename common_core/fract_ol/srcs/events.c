#include "fractol.h"

int mouse_event(int keycode, int x, int y, t_fractol *f)
{
    if (keycode == MOUSE_WHEEL_UP)
    {
        zoom(f, 0.5);
        x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(f, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(f, (double)x / WIDTH, 'R');
		if (y < 0)
			move(f, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (f, (double)y / HEIGHT, 'D');
    }
    else if (keycode == MOUSE_WHEEL_DOWN)
        zoom(f, 2);
    init_palette(f);
    render(f);
    return (0);
}

int exit_hook(t_fractol *fractol)
{
    ft_printf("Exiting program...\n");
    mlx_destroy_window(fractol->mlx, fractol->win);
    exit(0);
    return (0);
}