#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (dst[len] && len < dstsize)
		len++;
	if (dstsize <= len)
		return (len + ft_strlen(src));
	while (src[i] != '\0' && (len + i + 1) < dstsize)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		len;
	char	*joined;

	
	if (!s1)
		s1 = "";
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2;
	joined = (char *)malloc((len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, len_s1 + 1);
	ft_strlcat(joined, s2, len + 1);
	return (joined);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free((void *)s1);
	return (joined);
}

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	out_len;	

	out_len = ft_strlen(s1) + 1;
	out = (char *)malloc(out_len * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, out_len);
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*read_buffer(int fd, int *read_bytes)
{
	char	*buffer;
	
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*read_bytes] = '\0';
	return (buffer);
}

/*
char	*get_next_line(int fd)
{
	char	*line;
	static char	*buffer;
	char	*nu_line;
	static int	read_bytes;
    char    *temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	nu_line = NULL;
	if (!buffer)
    {
		buffer = read_buffer(fd, &read_bytes);
        if (read_bytes <= 0)
            return (line);
    }
	nu_line = ft_strchr(buffer, '\n');
	while (!nu_line && read_bytes == BUFFER_SIZE)
	{
		line = ft_strjoin_free(line, buffer);
        free(buffer);
		buffer = read_buffer(fd, &read_bytes);
        //printf("buffer: %s\n", buffer);
		nu_line = ft_strchr(buffer, '\n');
	}
	if (nu_line != 0)
	{
        line = ft_strjoin_free(line, ft_substr(buffer, 0, nu_line - buffer + 1));
        temp = buffer;
		buffer = ft_strdup(nu_line + 1);
        free(temp);
	}
	else
	{
		line = ft_strjoin_free(line, buffer);
		buffer = NULL;
	}
	return (line);
}
*/

void	set_line(char **line, char **buffer, char *nu_line)
{
	char	*temp;
	if (nu_line)
	{
		*line = ft_strjoin_free(*line, ft_substr(*buffer, 0, nu_line - *buffer + 1));
		if (ft_strlen(nu_line + 1) > 0)
		{
            printf("buffer is newline\n");
			temp = *buffer;
			*buffer = ft_strdup(nu_line + 1);
			free(temp);
		}
		else
		{
            printf("buffer is nullchar\n");
			free(*buffer);
			*buffer = NULL;
		}
	}
	else
	{
		*line = ft_strjoin_free(*line, *buffer);
    	free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*buffer;
	char	*nu_line;
	int	read_bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (!buffer)
    	{
			buffer = read_buffer(fd, &read_bytes);
			if (read_bytes <= 0)
            	return (line);
    	}
		nu_line = ft_strchr(buffer, '\n');
		set_line(&line, &buffer, nu_line);
		if (nu_line)
			return (line);
	}
}

int	main()
{
	char	*file = "./test.txt";
	int	fd = open(file, O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	printf("First line: %s", line);
	line = get_next_line(fd);
	printf("Second line: %s", line);
	line = get_next_line(fd);
	printf("Third line: %s", line);
	//printf("3===D~~~~");
}
