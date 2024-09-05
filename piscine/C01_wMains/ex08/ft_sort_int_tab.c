#include <unistd.h>

void	ft_putchar(char c)
{
        write(1, &c, 1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	t;
	int	n_changes;

	n_changes = 1;	
	while (n_changes != 0)
	{
		i = 0;
		n_changes = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				t = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = t;
				n_changes++;
			}
			i++;
		}
	}
}

int	main(void)
{
	int     arr[] = {4, 3, 2, 5, 1};
        int     size;
        int     i;

        size = 5;
        i = 0;
        ft_sort_int_tab(arr, size);
        while (i < size)
        {
                int     i_out = arr[i] + '0';
                ft_putchar(i_out);
                i++;
        }
        return (0);
}
