#include "get_next_line.h"

static char	*ft_strdup(const char *s1)
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

static char	*ft_substr(char const *s, unsigned int start, size_t len)
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

static char	*ft_strchr(const char *s, int c)
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

static char	*read_buffer(int fd, int *read_bytes)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*read_bytes] = '\0';
	return (buffer);
}

void	set_line(char **line, char **buffer, char *nu_line)
{
	char	*temp;
	if (nu_line)
	{
		*line = ft_strjoin_free(*line, ft_substr(*buffer, 0, nu_line - *buffer + 1));
		if (ft_strlen(nu_line + 1) > 0)
		{
			temp = *buffer;
			*buffer = ft_strdup(nu_line + 1);
			free(temp);
		}
		else
		{
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
			{
				free(buffer);
				buffer = NULL;
            	return (line);
			}
    	}
		nu_line = ft_strchr(buffer, '\n');
		set_line(&line, &buffer, nu_line);
		if (nu_line)
			return (line);
	}
}