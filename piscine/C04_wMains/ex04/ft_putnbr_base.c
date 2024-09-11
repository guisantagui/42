#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}


int	base_valid(char *base)
{
	int	is_val;
	int	i;

	is_val = 1;
	i = 0;
	while(base[i] == '\0' && is_val == 1)
	{
		if(is_num(base[i]) == 0)
			is_val = 0;
	}
	return (is_val);
}

int     atoi_cust(char *num)
{
	int     num_len;
	int     num_int;
	int     dix_mult;

	num_len = 0;
	dix_mult = 1;
	while (num[num_len])
		num_len++;
	while (num_len > 1)
	{
		dix_mult *= 10;
		num_len--;
	}
	if (num_len == 0)
		return (0);
        //if (*num == '-')
        //      return (-atoi_cust(num + 1));
	else
		return (*num - '0') * dix_mult + atoi_cust(num + 1);
}


char	*get_digits(int b)
{
	char	*digits;

	if (b == 10)
		digits = "0123456789";
	else if (b == 2)
		digits = "01";
	else if (b == 16)
		digits = "0123456789ABCDEF";
	else if (b == 8)
		digits = "poneyvif";
	return (digits);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b;
	char *digits;

	if (base_valid(base) == 1)
	{
		b = atoi_cust(base);
		digits = get_digits(b);
		if (nbr < 0)
		{
			ft_putchar('-');
			if (nbr == -2147483648)
			{
				ft_putchar('2');
				ft_putnbr_base(147483648, base);
			}
			else
				ft_putnbr_base(-nbr, base);
		}
		else if (nbr >= b)
			ft_putnbr_base(nbr / b, base);
		write(1, &digits[nbr % b], 1);
	}
}

int	main()
{
	int number = 16;
	ft_putnbr_base(number, "8");
	ft_putchar('\n');
	ft_putnbr_base(number, "8i8");
}
