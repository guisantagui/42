/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:45:14 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/14 18:46:43 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc > 1)
	{
		fractol = malloc(sizeof(t_fractol));
		if (!fractol)
		{
			ft_printf("Error\n");
			exit (1);
		}
		init_zero(fractol);
		parse_args(fractol, argc, argv);
		init(fractol);
		render(fractol);
		mlx_hook(fractol->win, 17, 0, exit_hook, fractol);
		mlx_mouse_hook(fractol->win, mouse_event, fractol);
		mlx_key_hook(fractol->win, key_event, fractol);
		mlx_loop(fractol->mlx);
	}
	return (0);
}
