#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 2

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

	if (!s1 || !s2)
		return (NULL);
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
/*
char	*read_buffer(int fd)
{
	char	*buffer;
	char	c;
	int	i;
	size_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0 && c != '\n' && c != '\0' && i < BUFFER_SIZE)
        {
		buffer[i] = c;
		bytes_read = read(fd, &c, 1);
		i++;
		if (c == '\n')
		{
			buffer[i] = c;
			i++;
			break;
		}
	}
	buffer[i] = '\0';
	return (buffer);
}
*/

char	read_buffer(int fd)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	read(fd, &buffer, BUFFER_SIZE);
	buffer[ft_strlen(buffer)] = '\0';
	return (buffer);
}

int	has_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	int	nu_line;

	line = '\0';
	nu_line = 0;

	while (nu_line == 0)
	{
		buffer = read_buffer(fd);
		nu_line = has_newline(buffer);
		if (nu_line == 1)
		{
			line = ft_strjoin_free(line, ft_split(buffer)[0]);
			
		}
		else
			line = ft_strjoin_free(line, buffer);
	}
	return (line);
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
	printf("3===D~~~~");
}
