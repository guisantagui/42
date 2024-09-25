#include <stdlib.h>
#include <stdio.h>

int	sum_one(int n)
{
	int	res;

	res = n + 1;
	return (res);
}

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*out;

	i = 0;
	out = (int *)malloc(length * sizeof(int));
	if (!out)
		return (NULL);
	while (i < length)
	{
		out[i] = f(tab[i]);
		i++;
	}
	return (out);
}

int	main()
{
	int	tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	*res = ft_map(tab, 10, &sum_one);
	int	i = 0;
	while (i < 10)
	{
		printf("%d\n", res[i]);
		i++;
	}
}
