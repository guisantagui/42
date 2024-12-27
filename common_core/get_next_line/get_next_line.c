#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 42


void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*res;

	res = malloc(num * size);
	if (!res)
		return (NULL);
	ft_bzero(res, (num * size));
	return (res);
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
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*read_file()

void	print_five(int *fd)
{
	int     i;
	char	c;
	size_t	bytes_read;

	i = 0;
        bytes_read = read(*fd, &c, 1);
	ft_putchar(c);
        while (bytes_read > 0 && i < 4)
        {	
		i++;
		bytes_read = read(*fd, &c, 1);
                ft_putchar(c);
        }
	*fd = *fd - i;
}

int	main()
{
	int	i;
	char	*file = "./test.txt";
	int	fd = open(file, O_RDONLY);

	print_five(&fd);
	ft_putchar('\n');
	print_five(&fd);
	ft_putchar('\n');
	print_five(&fd);
	ft_putchar('\n');
	print_five(&fd);
	ft_putchar('\n');	
}
