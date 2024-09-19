/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:32:50 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/19 19:33:53 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_strdup(char *src)
{
	char	*out;

	out = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!out)
		return (0);
	out = ft_strcpy(out, src);
	return (out);
}
/*
int	main(void)
{
	char	*str1 = "Hola";
	char	*str2 = ft_strdup(str1);
	printf("%s\n", str2);
}
*/
