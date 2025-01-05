#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 42

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

char	*read_buffer(int fd)
{
	char	*buffer;
	char	c;
	char	i;
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

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	int	buffer_len;

	line = read_buffer(fd);
	buffer_len = ft_strlen(line);
	while (buffer_len == BUFFER_SIZE)
	{
		buffer = read_buffer(fd);
		line = ft_strjoin_free(line, buffer);
		buffer_len = ft_strlen(buffer);
	}
	return (line);
}

/*
static int	get_line_len(int fd)
{
	int	len;
	char	c;
	size_t	bytes_read;

	len = 0;
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0)
	{
		len++;
		if (c == '\n')
			break;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	int	fd_start;
	char	*line;
	int	line_len;

	fd_start = fd;
	line_len = get_line_len(fd);
	line = (char *)malloc((sizeof(char) * line_len) + 1);
	if (line == NULL)
		return (NULL);
	read(fd_start, line, line_len);
	line[line_len] = '\0';
	return (line);
}
*/

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
