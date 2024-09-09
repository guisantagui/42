#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putstr(char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
        {
                ft_putchar(str[i++]);
        }
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i])
		i++;
	return (i);
}

int     main(void)
{
        char    str1[20] = "hola";
        char    str2[20];
	int	str1Len;

        str1Len = ft_strlcpy(str2, str1, 20);
        ft_putstr(str2);
	
}
