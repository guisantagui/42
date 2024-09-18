#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int     i;

	*range = (int*)malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
/*
int	main()
{
	int     min = 20;
	int     max = 155;
	int     i = 0;
	int     *arr;
	int size = ft_ultimate_range(&arr, min, max);

	printf("Size = %d\n", size);
	while (i < max - min)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}
*/
