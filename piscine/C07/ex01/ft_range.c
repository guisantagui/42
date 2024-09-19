/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:35:02 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/19 19:35:44 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	range = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	if (min >= max)
		return (0);
	while (min + i < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
int	main()
{
	int	min = 20;
	int	max = 155;
	int	i = 0;
	int	*arr;
	arr = ft_range(min, max);

	while (i < max - min)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}
*/
