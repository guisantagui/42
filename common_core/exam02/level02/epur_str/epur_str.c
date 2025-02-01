#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	skip_spaces(int i, char *str)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i;
		i = 0;
		i = skip_spaces(i, av[1]);
		while (av[1][i])
		{
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				ft_putchar(av[1][i]);
				i++;
			}
			else
			{
				ft_putchar(' ');
				i = skip_spaces(i, av[1]);
			}
		}
	}
	ft_putchar('\n');
}
