#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char     *get_next_line(int fd);
char	*ft_strdup(const char *s1);
size_t  ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_strjoin_free(char const *s1, char const *s2, int free_both);

#endif
