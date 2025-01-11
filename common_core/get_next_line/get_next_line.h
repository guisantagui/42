#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char     *get_next_line(int fd);
size_t  ft_strlen(const char *str);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_strjoin(char const *s1, char const *s2);

#endif
