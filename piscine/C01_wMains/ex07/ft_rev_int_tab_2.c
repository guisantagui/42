#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	t;


	i = 0;
	while (i < size / 2)
	{
		t = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = t;	
		i++;
	}
}

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5};
	int	size;
	int	i;

	size = 5;
	i = 0;
	ft_rev_int_tab(arr, size);
	while (i < size)
	{
		int	i_out = arr[i] + '0';
		ft_putchar(i_out);
		i++;
	}
	return (0);
}
