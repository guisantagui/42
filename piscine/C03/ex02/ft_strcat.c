/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:52:20 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/10 17:52:23 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = src[i];
	return (dest);
}

/*int	main()
{
	char str1[50] = "Hola, ";
	char str2[20] = "Mundo!";

	ft_strcat(str1, str2);
	printf("Result: %s\n", str1);
}*/
