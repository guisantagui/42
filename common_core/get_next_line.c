#include <unistd.h>
#include <stdlib.h>

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
