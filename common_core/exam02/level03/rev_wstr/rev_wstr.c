#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_word(char *str, int start, int end)
{
	while (start <= end)
	{
		ft_putchar(str[start]);
		start++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;
	int	first_word;

	i = 0;
	first_word = 1;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (i >= 0)
		{
			while (av[1][i] == '\0' || av[1][i] == ' ' || av[1][i] == '\t')
				i--;
			end = i;
			while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t')
				i--;
			start = i + 1;
			if (!first_word)
				ft_putchar(' ');
			first_word = 0;
			print_word(av[1], start, end);
		}
	}
	ft_putchar('\n');
}
