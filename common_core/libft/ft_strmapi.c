//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

/*
size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
*/

static char    incr_by_i(unsigned int i, char c)
{
    char    out;

    out = c + i;
    return (out);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    size_t          len;
    char            *out;

    i = 0;
    len = ft_strlen((char *)s);
    out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
    while (i < len)
    {
        out[i] = f(i, s[i]);
        i++;
    }
    out[i] = '\0';
    return (out);
}
/*
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        printf("Original string: %s\n", argv[1]);
        printf("Modified string: %s\n", ft_strmapi(argv[1], &incr_by_i));
    }
}
*/