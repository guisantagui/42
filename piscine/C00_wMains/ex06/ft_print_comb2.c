#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	int_2_char(int n)
{
	char c;

	c = n + '0';
	return(c);
}

void	num_twoDig(int n)
{
	int units;
	int tens;
	char unitsC;
	char tensC;

	units = n % 10;
	tens = (n - units)/10;
	unitsC = int_2_char(units);
	tensC = int_2_char(tens);
	ft_putchar(tensC);
	ft_putchar(unitsC);
}

void	ft_print_comb2(void)
{
	int num1;
	int num2;

	num1 = 0;
	while (num1 < 99)
	{
		num2 = num1 + 1;
		while (num2 < 100)
		{
			if(num1 != num2)
			{
				num_twoDig(num1);
                        	ft_putchar(' ');
                        	num_twoDig(num2);
                        	if(!(num1 == 98 && num2 == 99))
                        	{       
                                	ft_putchar(',');
                                	ft_putchar(' ');
                        	}
			}
			num2++;
		}
		num1++;
	}
}


int	main()
{
	ft_print_comb2();
	return(0);
}
