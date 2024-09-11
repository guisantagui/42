#include <unistd.h>
//#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	has_dups(char *str)
{
	int	i;
	int	j;
	int	h_dups;

	i = 0;
	h_dups = 0;
	while (str[i] != '\0' && h_dups == 0)
	{
		j = i + 1;;
		while (str[j])
		{
			if (str[i] == str[j])
				h_dups = 1;
			j++;
		}
		i++;	
	}
	return (h_dups);
}

int	base_valid(char *base)
{
	int	is_val;
	int	i;
	int	base_len;

	is_val = 1;
	i = 0;
	base_len = ft_strlen(base);
	if(base_len < 2 || has_dups(base) == 1)
		is_val = 0;
	while(base[i] != '\0' && is_val == 1)
	{
		if(base[i] == '+' || base[i] == '-')
			is_val = 0;
		i++;
	}
	return (is_val);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b;

	if (base_valid(base) == 1)
	{
		b = ft_strlen(base);
		if (nbr < 0)
		{
			if (nbr == -2147483648)
			{
				ft_putchar('-');
				ft_putnbr_base(-(nbr / b), base);
				//ft_putchar(base[-(nbr % b)]);
			}
			else
				ft_putchar('-');
				nbr *= -1;
		}
		if (nbr >= b)
			ft_putnbr_base(nbr / b, base);
		write(1, &base[nbr % b], 1);
	}
}

/*int	main()
{
	int number = 20;
	printf("Number %d in base %s\n", number, "01");
	ft_putnbr_base(number, "01");
	ft_putchar('\n');
	printf("Number %d in base %s\n", number, "0123456789ABCDEF");
	ft_putnbr_base(number, "0123456789ABCDEF");
        ft_putchar('\n');
	printf("Number %d in base %s\n", number, "0123456789");
        ft_putnbr_base(number, "0123456789");
        ft_putchar('\n');
	printf("Number %d in base %s\n", number, "poneyvif");
        ft_putnbr_base(number, "poneyvif");
        ft_putchar('\n');
	printf("Number %d in base %s\n", number, "012345677");
        ft_putnbr_base(number, "012345677");
        ft_putchar('\n');
	printf("Number %d in base %s\n", number, "abcd+");
        ft_putnbr_base(number, "abcd+");
        ft_putchar('\n');
	number = -12;
	printf("Number %d in base %s\n", number, "01");
        ft_putnbr_base(number, "01");
        ft_putchar('\n');
	number = 12;
        printf("Number %d in base %s\n", number, "01");
        ft_putnbr_base(number, "01");
        ft_putchar('\n');
	number = -2147483648;
	printf("Number %d in base %s\n", number, "01");
        ft_putnbr_base(number, "01");
        ft_putchar('\n');
}*/
