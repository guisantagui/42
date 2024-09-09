#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i++]);
	}
}

int	is_alpha_num(char c)
{
	int	is_num;
	int	is_up;
	int	is_low;
	int	is_alph_num;

	is_num = 0;
	is_up = 0;
	is_low = 0;
	if (c >= 97 && c <= 122)
		is_low = 1;
	if (c >= 65 && c <= 90)
		is_up = 1;
	if (c >= 48 && c <= 57)
		is_num = 1;

	if (is_num == 1 || is_up == 1 || is_low == 1)
		is_alph_num = 1;
	else
		is_alph_num = 0;
	return (is_alph_num);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	w_idx;
	int	is_alph_num;

	i = 0;
	w_idx = 0;
	while(str[i])
	{
		is_alph_num = is_alpha_num(str[i]);
		if ((str[i] >= 97 && str[i] <= 122) && w_idx == 0)
			str[i] = str[i] - 32;
		else if ((str[i] >= 65 && str[i] <= 90) && w_idx != 0)
			str[i] = str[i] + 32;
		if (is_alph_num == 0)
			w_idx = 0;
		else
			w_idx++;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str1[40] = "HELLO cARaCoLa 92 mONOLOCO";
	ft_strcapitalize(str1);
	ft_putstr(str1);
}
