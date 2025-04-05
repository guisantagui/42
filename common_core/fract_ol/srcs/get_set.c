#include "fractol.h"

static void    toupper_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
}

static void    get_set_char(t_fractol *f, char **argv)
{
    if (argv[1][0] == 'J' || argv[1][0] == '1')
        f->set = 1;
    else if (argv[1][0] == 'M' || argv[1][0] == '2')
        f->set = 2;
    else if (argv[1][0] == 'B' || argv[1][0] == '3')
        f->set = 3;
    else if (argv[1][0] == 'N' || argv[1][0] == '4')
        f->set = 4;
    else
        free_exit(f);
}

static void    get_set_str(t_fractol *f, char **argv)
{
    if (ft_strncmp(argv[1], "JULIA", ft_strlen(argv[1])) == 0)
        f->set = 1;
    else if (ft_strncmp(argv[1], "MANDELBROT", ft_strlen(argv[1])) == 0)
        f->set = 2;
    else if (ft_strncmp(argv[1], "BURNING SHIP", ft_strlen(argv[1])) == 0)
        f->set = 3;
    else if (ft_strncmp(argv[1], "NEWTON", ft_strlen(argv[1])) == 0)
        f->set = 4;
    else
        free_exit(f);
}

void    get_set(t_fractol *f, char **argv)
{
    toupper_str(argv[1]);
    if (ft_strlen(argv[1]) == 1)
        get_set_char(f, argv);
    else
        get_set_str(f, argv);
}