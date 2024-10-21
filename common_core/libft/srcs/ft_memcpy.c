void	*memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
