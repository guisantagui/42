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

	ft_strcpy(hex, "0123456789ABCDEF");
	//if (n >= 16)
	//{
		//int_to_hex(n / 16);
	//}
	//else
		ft_putchar(hex[n / 16]);
		ft_putchar(hex[n % 16]);
}

int	main()
{
	int n1 = 10;
	int n2 = 20;
	int n3 = 30;

	int_to_hex(n1);
	ft_putchar('\n');
	int_to_hex(n2);
        ft_putchar('\n');
	int_to_hex(n3);
        ft_putchar('\n');

	return (0);
}
