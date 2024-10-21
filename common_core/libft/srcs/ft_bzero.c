void	bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}
