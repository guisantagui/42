/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:54:03 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/10 18:22:05 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*substr_chk(char *str, char *to_find, int pos)
{
	int	f_match;
	int	i;

	f_match = pos;
	i = 0;
	while (str[pos] == to_find[i] && to_find[i] != '\0' && str[pos] != '\0')
	{
		i++;
		pos++;
	}
	if (to_find[i] == '\0')
		return (str + f_match);
	else
		return (NULL);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*p_out;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[j] != '\0')
	{
		if (str[j] == to_find[i])
		{
			p_out = substr_chk(str, to_find, j);
			if (p_out != NULL)
				return (p_out);
		}
		j++;
	}
	return (NULL);
}

/*int main() {
    char str[] = "Hello, world!";
    char sub[] = "world";

    char *result = ft_strstr(str, sub);
    if (result != NULL) {
        printf("Substring found: %s\n", result);
    } else {
        printf("Substring not found.\n");
    }
    return 0;
}*/
