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

int	key_event(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Exiting program...\n");
        free_fractol(f);
        exit(0);
        return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(f, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(f, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(f, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(f, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(f, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(f, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		shift_cols(f);
	//else if (!key_event_extend(keycode, mlx))
	//	return (1);
	else
		return (1);
    init_palette(f);
	render(f);
	return (0);
}

int exit_hook(t_fractol *fractol)
{
    ft_printf("Exiting program...\n");
    free_fractol(fractol);
    exit(0);
    return (0);
}