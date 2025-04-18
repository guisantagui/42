/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:23:29 by gsantama          #+#    #+#             */
/*   Updated: 2024/12/01 18:57:08 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0') && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%s vs %s, n = %s: %d", argv[1], argv[2], argv[3], 
		ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	}
}
*/
