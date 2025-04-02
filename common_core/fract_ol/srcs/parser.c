#include "fractol.h"

double  ft_atod(char *str)
{
    double res;
    int i;
    double dec_div;
    char    **split;
    int sign;

    res = 0;
    dec_div = 1;
    split = ft_split(str, '.');
    sign = 1;
    ft_printf("%s\n", split[0]);
    ft_printf("%s\n", split[1]);
    res = (double)ft_atoi_cust(split[0], &sign);
    if (split[1] != NULL)
    {
        i = skip_spaces(split[1]);
        while (split[1][i] && ft_isdigit(split[1][i]))
        {
            dec_div *= 0.1;
            res += (split[1][i] - '0') * dec_div;
            i++;
        }
    }
    free_arr(split);
    return (res * sign);
}

int ft_atox(char *str)
{
    int res;
    char digits[17];
    int i;
    int j;
    int n_digs;

    res = 0;
    ft_strlcpy(digits, "0123456789ABCDEF", 17);
    i = skip_spaces(str);
    n_digs = 0;
    while (str[i] && ft_strchr(digits, (int)str[i]) != NULL)
    {
        j = 0;
        res *= 16;
        while (digits[j])
        {
            if (ft_toupper(str[i]) == digits[j])
            {
                res += j;
                break;
            }
            j++;
        }
        i++;
        n_digs++;
    }
    if (n_digs == 6 && str[i] == '\0')
        return (res);
    else
        return (-42);
}

void    toupper_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
}

void    get_set(t_fractol *f, char **argv)
{
    toupper_str(argv[1]);
    if (ft_strlen(argv[1]) == 1)
    {
        if (argv[1][0] == 'J' || argv[1][0] == '1')
            f->set = 1;
        else
        {
            ft_printf("The introduced fractal is not supported.\n");
            exit(1);
        }
    }
    else{
        if (ft_strncmp(argv[1], "JULIA", ft_strlen(argv[1])) == 0)
            f->set = 1;
        else
        {
            ft_printf("The introduced fractal is not supported.\n");
            exit(1);
        }
    }
    
}

void    set_julia_cnstnts(t_fractol *f, char **argv)
{
    f->kr = ft_atod(argv[2]);
    f->ki = ft_atod(argv[3]);
    if (f->kr < -2)
        f->kr = -2;
    else if (f->kr > 2)
        f->kr = 2;
    if (f->ki < -2)
        f->ki = -2;
    else if (f->ki > 2)
        f->ki = 2;
}

void    parse_args(t_fractol *f, int argc, char **argv)
{
    int i;
    if (argc > 1)
    {
        get_set(f, argv);
        if (f->set == 1)
        {
            if (argc >= 5)
            {
                set_julia_cnstnts(f, argv);
                f->color = malloc(sizeof(int) * argc - 4);
                f->n_cols = argc - 4;
                if (!f->color)
                    exit (1);
                i = 4;
                while (i < argc)
                {
                    printf("color arg %d: %s. ATOD: %d\n", i, argv[i], ft_atox(argv[i]));
                    f->color[i - 4] = ft_atox(argv[i]);
                    i++;
                }
            }
            else if (argc == 4)
            {
                f->kr = ft_atod(argv[2]);
                f->ki = ft_atod(argv[3]);
                f->color = malloc(sizeof(int));
                if (!f->color)
                    exit (1);
                f->color[0] = 0xFFFFFF;
                f->n_cols = 1;
            }
            ft_printf("n_cols: %d\n", f->n_cols);
        }
    }
}