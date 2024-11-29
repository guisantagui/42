/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:22:37 by gsantama          #+#    #+#             */
/*   Updated: 2024/11/29 15:28:44 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static void	incr_by_i(unsigned int i, char *c)
{
	*c = *c + i;
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        printf("Original string: %s\n", argv[1]);
        ft_striteri(argv[1], &incr_by_i);
        printf("Modified string: %s\n", argv[1]);
    }
}
*/
