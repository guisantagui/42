#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <math.h>

# define WIDTH  1024
# define HEIGHT 768
# define MAX_ITER 100
# define ZOOM 1.0
# define MOVE_X 0.0
# define MOVE_Y 0.0

// Keys macros
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3

// Keys MacOS
# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// Keys Linux
/*
# define KEY_ESC 65307
# define KEY_SPACE 32
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
*/

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
int color_shift_hue(int color, double hue_shift);
void shift_cols(t_fractol *f);

// Moves
void    zoom(t_fractol *f, double zoom);
void	move(t_fractol *f, double distance, char direction);

// Events
int mouse_event(int keycode, int x, int y, t_fractol *f);
int	key_event(int keycode, t_fractol *f);
int exit_hook(t_fractol *fractol);

// Parser
int	ft_atoi_cust(const char *str, int *sign);
void    free_arr(char **arr);
int    skip_spaces(char *str);
void    parse_args(t_fractol *f, int argc, char **argv);

// Cleanup
void    free_fractol(t_fractol *f);
void    free_exit(t_fractol *f);

#endif