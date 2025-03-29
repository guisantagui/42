#include "fractol.h"

#define PI 3.141592653589793

int add_shade(int color, double shade)
{
    int t;
    int r;
    int g;
    int b;

    t = get_t(color);
    r = get_r(color) * shade;
    g = get_g(color) * shade;
    b = get_b(color) * shade;
    return (create_trgb(t, r, g, b));
}

void    do_cycles(t_data *img, int color, int cycles)
{
    int x;
    int y;
    int nu_col;
    double  shade_1;
    double  shade_2;
    int r, g, b, t;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            t = get_t(color);
            r = get_r(color);
            g = get_g(color);
            b = get_b(color);

            r = (int)((double)x * ((double)255 / WIDTH));
            g = (int)((double)y * ((double)255 / HEIGHT));
            
            shade_1 = (sin((double)x/(((double)WIDTH/360) / cycles) * PI/180) + 1)/ 2;
            shade_2 = (sin((double)y/(((double)WIDTH/360) / cycles) * PI/180) + 1)/ 2;
            b = (int)(b - (255 * shade_1));
            nu_col = create_trgb(t, r, g, b);
            //printf("B: %d\n", b);
            nu_col = add_shade(nu_col, shade_1 * shade_2);
            my_mlx_pixel_put(img, x, y, nu_col);
            x++;
        }
        y++;
    }
}

void    fill_window_with_color(t_data *img, int color)
{
    int x;
    int y;

    // Loop through every pixel on the window and set it to red
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            my_mlx_pixel_put(img, x, y, color);  // Red color
        }
    }
}

/*
void    do_gradient(t_data *img, int color)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            my_mlx_pixel_put(img, x, y, add_shade(color, (double)x / WIDTH));
            x++;
        }
        y++;
    }
}
*/
/*
int julia(double real, double img, double c_re, double c_im) {
    int i = 0;
    double z_re = real, z_im = img;
    
    while (z_re * z_re + z_im * z_im <= 4 && i < MAX_ITER) {
        double temp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = temp;
        i++;
    }
    return i;
}


void draw_julia_set(t_data *img, double c_re, double c_im) {
    int x, y;
    double real, imag;
    int color;
    int max_iter = MAX_ITER;
    
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            real = (x - WIDTH / 2) * ZOOM / WIDTH + MOVE_X;
            imag = (y - HEIGHT / 2) * ZOOM / HEIGHT + MOVE_Y;
            
            int iterations = julia(real, imag, c_re, c_im);
            if (iterations == max_iter)
                color = create_trgb(0, 0, 0, 0); // Black if inside Julia set
            else
                color = create_trgb(0, iterations % 256, iterations % 64, iterations % 128); // Color based on iterations

            // Put pixel in image
            my_mlx_pixel_put(img, x, y, color);
        }
    }
}
*/


int main(void)
{
    //t_fractol   *fractol;

    //fractol = malloc(sizeof(t_fractol));
    void    *mlx;
    void    *window;
    t_data  img;
    int color;

    //init_mlx(fractol);
    //render(fractol);
    color = create_trgb(0, 0, 0, 255);
    //ft_printf("Col hex: %X\n", color);
    //ft_printf("Col int: %d\n", color);
    // Initialize the MiniLibX connection to the display
    mlx = mlx_init();
    if (!mlx)
    {
        // If mlx_init fails, print error and return
        write(2, "Error initializing mlx.\n", 24);
        return (1);
    }

    // Create a new window (width, height, title)
    window = mlx_new_window(mlx, WIDTH, HEIGHT, "MiniLibX Test");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    //my_mlx_pixel_put(&img, 5, 5, color);
    //mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    // Fill the window with a color (e.g., red: 0xFF0000)
    mlx_clear_window(mlx, window);
    fill_window_with_color(&img, color);
    //do_gradient(&img, color);
    //do_cycles(&img, color, 20);
    printf("Image filled\n");
    //double  c_re = -0.766667;
    //double  c_im = -0.090000;
    //draw_julia_set(&img, c_re, c_im);
    mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    //mlx_string_put(mlx, window, 10, 10, 0xFFFFFF, "Hello, MiniLibX!");

    // Enter the event loop (the window will remain open until closed)
    mlx_loop(mlx);
    //mlx_loop(fractol->mlx);
    return (0);
}