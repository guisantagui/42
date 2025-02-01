#include <stdlib.h>
#include <stdio.h>

int	abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	*ft_range(int start, int end)
{
	int	size;
	int	*range;
	int	i;

	size = abs(end - start) + 1;
	range = (int *)malloc(sizeof(int) * size);
	i = 0;
	if (!range)
		return (NULL);
	while (i < size)
	{
		if (start < end)
			range[i] = end - i;
		else
			range[i] = end + i;
		i++;
	}
	return (range);
}

int	main(int ac, char **av)
{
	int	*out;
	int	start;
	int	end;
	int	size;
	int	i;

	if (ac == 3)
	{
		start = atoi(av[1]);
		end = atoi(av[2]);
		size = abs(end - start) + 1;
		out = ft_range(start, end);
		i = 0;

		while (i < size)
		{
			printf("%d\n", out[i]);
			i++;
		}
	}
}
