/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:53:20 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/11 20:59:13 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	shift_hue(double *norm_rgb, double *hsv,
				double hue_shift, int *is_error)
{
	double	*ifpqt;

	hsv[0] = fmod(hsv[0] + hue_shift, 6.0);
	if (hsv[0] < 0)
		hsv[0] += 6.0;
	if (hsv[1] == 0.0)
	{
		set_rgb(norm_rgb, hsv[2], hsv[2], hsv[2]);
		return ;
	}
	ifpqt = get_ifpqt(hsv);
	if (!ifpqt)
		*is_error = 1;
	else
	{
		set_rgb_hsv_ifpqt(norm_rgb, ifpqt, hsv);
		free(ifpqt);
	}
}

static int	color_shift_hue(int color, double hue_shift)
{
	double	*col_hsv;
	double	*hsv;
	int		shift_col;
	int		is_error;

	is_error = 0;
	col_hsv = norm_trgb(color);
	if (!col_hsv)
		return (-42);
	hsv = get_hsv(col_hsv);
	if (!hsv)
	{
		free(col_hsv);
		return (-42);
	}
	shift_hue(col_hsv, hsv, hue_shift, &is_error);
	free(hsv);
	if (is_error == 0)
		shift_col = create_trgb(0, (int)(col_hsv[2] * 255),
				(int)(col_hsv[1] * 255), (int)(col_hsv[0] * 255));
	else
		shift_col = -42;
	free(col_hsv);
	return (shift_col);
}

void	shift_cols(t_fractol *f)
{
	int	i;
	int	shift_col;

	i = 0;
	while (i < f->n_cols)
	{
		shift_col = color_shift_hue(f->color[i], 0.5);
		if (shift_col < 0)
			free_exit(f);
		f->color[i] = shift_col;
		i++;
	}
}
