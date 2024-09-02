#include <unistd.h>

char	conv_2_char(int n)
{
	char out;

	out = n + '0';
	return (out);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	num1;
	int	num2;
	int 	num3;
	int countShift;
	char wOut1;
	char wOut2;
	char wOut3;

	num1 = 0;	
	countShift = 0;
	while (num1 <= 7)
	{
		countShift = 0;
		num2 = 1 + num1 + countShift;
		wOut1 = conv_2_char(num1);
		while (num2 <= 8)
		{
			num3 = num2 + 1;
			wOut2 = conv_2_char(num2);
			while (num3 <= 9)
			{
				wOut3 = conv_2_char(num3);
                                ft_putchar(wOut1);
				ft_putchar(wOut2);
				ft_putchar(wOut3);
				if(!(num1 == 7 && num2 == 8 && num3 == 9))
				{
					ft_putchar(',');
	                                ft_putchar(' ');
				}
				num3++;
			}
			num2++;
			countShift++;
		}
		num1++;
	}
}

int	main(void)
{
	ft_print_comb();
	return 0;
}
