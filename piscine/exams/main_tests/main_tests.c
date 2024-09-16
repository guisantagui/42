#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	printf("Number of arguments: %d\n", argc);
	while (i < argc)
	{
		printf("Argument %d: %s\n", i, argv[i]);
		i++;
	}
}
