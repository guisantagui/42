#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

int	main(void)
{
	printf("%d\n", (int)ft_strcspn("abcdefgh", "fgh"));
}
