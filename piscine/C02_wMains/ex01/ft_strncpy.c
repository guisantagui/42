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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int     main(void)
{
        char    str1[20] = "hola caracola";
        char    str2[20];
        ft_strncpy(str2, str1, 17);
        ft_putstr(str2);
}
