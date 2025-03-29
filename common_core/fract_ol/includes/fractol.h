#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
//# include "keys.h"
# include <stdio.h>
# include <math.h>

# define WIDTH  1024
# define HEIGHT 768
# define MAX_ITER 300
# define ZOOM 1.0
# define MOVE_X 0.0
# define MOVE_Y 0.0

typedef struct	s_data {
	void    *img;
	char    *addr;
	int	    bits_per_pixel;
	int	    line_length;
	int	    endian;
}           t_data;

typedef struct  s_fractol
{
    void    *mlx;
    void    *win;
    t_data  *img;
    double  kr;
    double  ki;
    double  r_min;
    double  r_max;
    double  i_min;
    double  i_max;
    char    *set;
}           t_fractol;

void    init_mlx(t_fractol *fractol);
int julia(t_fractol *f, double z_re, double z_im);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    render(t_fractol *f);

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

#endif