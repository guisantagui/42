#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

int     ft_str_is_printable(char *str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                if ((str[i] < 32) || (str[i] > 126))
                        return (0);
                i++;
        }
        return (1);
}

int     main()
{
        char    str1[20] = "\x01\x05\x0A\x15";
        char    str2[20] = "H0l4 C4r4cu10";
        int     is_alph1 = ft_str_is_printable(str1);
        int     is_alph2 = ft_str_is_printable(str2);
        ft_putchar(is_alph1 + '0');
        ft_putchar(is_alph2 + '0');
}
