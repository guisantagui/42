/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:00:02 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/26 20:02:48 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
/*
int	int_cmp(int n1, int n2)
{
	return (n1 - n2);
}
*/
int	ft_is_sort_asc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort_desc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_sort_asc(tab, length, f) || ft_is_sort_desc(tab, length, f))
		return (1);
	else
		return (0);
}
/*
int	main()
{
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[5] = {10, 7, 5, 3, 0};
	int arr3[5] = {1, 5, 3, 5, 7};
	printf("%d\n", ft_is_sort(arr1, 5, int_cmp));
	printf("%d\n", ft_is_sort(arr2, 5, int_cmp));
	printf("%d\n", ft_is_sort(arr3, 5, int_cmp));
}
*/
