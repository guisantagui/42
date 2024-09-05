void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tab_rev[size];

	i = 0;
	while (i < size)
	{
		tab_rev[i] = tab[size - 1 - i];
		i++;
	}
	i = 0;
	while (i < size){
		tab[i] = tab_rev[i];
		i++;
	}
}
