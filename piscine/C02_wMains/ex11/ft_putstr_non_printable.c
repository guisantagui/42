#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	int_to_hex(int n)
{
	char hex[16];

	ft_strcpy(hex, "0123456789abcdef");
	ft_putchar(hex[n / 16]);
	ft_putchar(hex[n % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		unsigned char	c = (unsigned char)str[i];
		if (str[i] >= 0 && str[i] <= 31)
		{
			ft_putchar('\\');
			//ft_putchar('0');
			int_to_hex(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

int	main()
{
	char str[24] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
	return (0);
}
