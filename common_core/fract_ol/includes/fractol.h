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

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3

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
    int *palette;
    int    set;
    int    *color;
    int n_cols;
    double zoom;
    int max_iters;
}           t_fractol;

// Initialization and computation
void    init_zero(t_fractol *f);
void    init(t_fractol *f);
int julia(t_fractol *f, double z_re, double z_im);
void    render(t_fractol *f);

// Color stuff
int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
int add_shade(int color, double shade);
int interpol_cols(int col_1, int col_2, double fraction);
void    init_palette(t_fractol *f);

// Moves
void    zoom(t_fractol *f, double zoom);
void	move(t_fractol *f, double distance, char direction);

// Events
int mouse_event(int keycode, int x, int y, t_fractol *f);
int exit_hook(t_fractol *fractol);

// Parser
int	ft_atoi_cust(const char *str, int *sign);
void    free_arr(char **arr);
int    skip_spaces(char *str);
void    parse_args(t_fractol *f, int argc, char **argv);

#endif