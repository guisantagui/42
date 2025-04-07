#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <math.h>

# define WIDTH  1024
# define HEIGHT 768
# define MAX_ITER 64
# define ZOOM 1.0
# define MOVE_X 0.0
# define MOVE_Y 0.0
# define PI 3.14159265359

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

// Sets
int julia(t_fractol *f, double z_re, double z_im);
int mandelbrot(t_fractol *f, double c_re, double c_im);
int burning_ship(t_fractol *f, double c_re, double c_im);
int newton(t_fractol *f, double z_re, double z_im, char *which);
int	julia_shift(int x, int y, t_fractol *f);

// Initialization and computation
void    init_zero(t_fractol *f);
void    init(t_fractol *f);
void    render(t_fractol *f);

// TRGB operations
int *get_trgb(int color);
int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

// Palette
int interpol_cols(int col_1, int col_2, double fraction);
void    init_palette(t_fractol *f);

// Color shifts
//int color_shift_hue(int color, double hue_shift);
double *norm_trgb(int color);
double  *get_hsv(double *norm_rgb);
void set_rgb(double *rgb, double r, double g, double b);
double *get_ifpqt(double *hsv);
void    set_rgb_hsv_ifpqt(double *norm_rgb, double *ifpqt, double *hsv);
void shift_cols(t_fractol *f);

// Moves
void    zoom(t_fractol *f, double zoom);
void	move(t_fractol *f, double distance, char direction);

// Events
int mouse_event(int keycode, int x, int y, t_fractol *f);
int	key_event(int keycode, t_fractol *f);
int exit_hook(t_fractol *fractol);

// Parser utils
int	ft_atoi_cust(const char *str, int *sign);
double  ft_atod(char *str);
void    free_arr(char **arr);
int    skip_spaces(char *str);

// Parser
void    get_set(t_fractol *f, char **argv);
void    set_bounds(t_fractol *f, double min, double max, double i_offset);
void    parse_args(t_fractol *f, int argc, char **argv);

// Color set
void    set_color(t_fractol *f, int i_o, int argc, char **argv);

// Cleanup
void    free_fractol(t_fractol *f);
void    free_exit(t_fractol *f);

#endif