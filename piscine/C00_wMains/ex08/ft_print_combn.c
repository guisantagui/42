#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int*	init_array(int n)
{
	static int	arr_i[1000];
	int	i;

	i = 0;
	while (i < n)
	{
		arr_i[i] = i;
		i++;
	}
	return(arr_i);
}

int*    finl_array(int n)
{
        static int      arr_f[1000];
        int     i;

        i = 0;
        while (n > 0)
        {
                arr_f[i] = 10 - n;
                i++;
		n--;
        }
        return(arr_f);
}

void	update_array(int arr_i[], int arr_f[], int arr_t[], int n)
{
	int	p;

	p = n - 1;
	while (p > 0)
	{
		if (arr_t[p] > arr_f[p])
		{
			arr_t[p - 1] = arr_i[p - 1] + 1;
			arr_i[p] = arr_i[p] + 1;
			arr_t[p] = arr_i[p];
		}
	}
}

void	w_comma_spac(int arr1[], int arr2[], int n)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (i < n)
	{
		if (arr1[i] == arr2[i])
		{
			count++;
		}
		i++;
	}
	if (count != n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_putarr(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
}

int 	main()
{
	int	numero;
	int*	array_i;
	int*	array_f;
	int    array_t[1000];

	numero = 4;
	array_i = init_array(numero);
	array_t = array_f;
	array_t[3] +=;
	array_t[2] -=;
	array_f = finl_array(numero);
	update_array(array_i, array_f,array_t, numero);
	ft_putarr(array_i, numero);
	w_comma_spac(array_i, array_t, numero);
	ft_putarr(array_t, numero);
	w_comma_spac(array_t, array_f, numero);
	ft_putarr(array_f, numero);
	//ft_print_combn(numero);
}
