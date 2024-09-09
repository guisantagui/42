#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv)
{
	int	i;
	//char	*str;
	int	found_d;

	found_d = 0;
	if (argc >= 2)
	{
		i = 0;
		//str = argv[1];
        	//while (str[i] && found_d == 0)
		while (argv[1][i] && found_d == 0)
        	{
			//if(str[i] == 'd')
			//if (argv[1][i] == 'd)
			{
				//ft_putchar(str[i]);
				ft_putchar(argv[1][i]);
				found_d = 1;
			}
                	i++;
        	}
	}
	ft_putchar('\n');
}
