#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

int     skip_spaces(char *str, int i)
{
        while (str[i] && is_space(str[i]) == 1)
                i++;
        return (i);
}

void	expand_str(char *str, int n_spaces)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	i = skip_spaces(str, i);
	while (str[i])
	{
		while (str[i] && is_space(str[i]) == 0)
		{
			ft_putchar(str[i]);
			i++;
		}
		if (is_space(str[i]) == 1)
		{
			i = skip_spaces(str, i);
			if (str[i])
			{
				while (n < n_spaces)
				{
					ft_putchar(' ');
					n++;
                        	}
				n = 0;
			}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		expand_str(av[1], 3);
	}
	ft_putchar('\n');
}
