/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:51:48 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/10 17:51:50 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n -1)
		i++;
	return (s1[i] - s2[i]);
}

/*int	main()
{
	char s1[20] = "Hola";
	char s2[20] = "HolA";
	char s3[20] = "Perro";
	char s4[20] = "Perramanola";

	printf("%d\n", ft_strncmp(s1, s1, 4));
	printf("%d\n", ft_strncmp(s1, s2, 3));
	printf("%d\n", ft_strncmp(s1, s2, 4));
	printf("%d\n", ft_strncmp(s2, s3, 4));
	printf("%d\n", ft_strncmp(s3, s4, 3));
	printf("%d\n", ft_strncmp(s3, s4, 4));
}*/
