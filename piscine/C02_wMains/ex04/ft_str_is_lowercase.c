#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

int     ft_str_is_lowercase(char *str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                if ((str[i] < 97) || (str[i] > 122))
                        return (0);
                i++;
        }
        return (1);
}

int     main()
{
        char    str1[20] = "holacaraculo";
        char    str2[20] = "Hola";
        int     is_alph1 = ft_str_is_lowercase(str1);
        int     is_alph2 = ft_str_is_lowercase(str2);
        ft_putchar(is_alph1 + '0');
        ft_putchar(is_alph2 + '0');
}
