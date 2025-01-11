#include "get_next_line.h"

static char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free((void *)s1);
	return (joined);
}

static char	*read_buffer(int fd)
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
		if (c == '\n' && i < BUFFER_SIZE)
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


	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
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
