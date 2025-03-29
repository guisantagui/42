/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:22:09 by gsantama          #+#    #+#             */
/*   Updated: 2024/11/30 15:26:15 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	int		i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}
/*
static void	free_arr(char **arr, int i)
{
	while (i-- > 0)
		free(arr[i]);
	free(arr);
}
*/

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	size_t	w_len;

	split = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				w_len = ft_strlen(s);
			else
				w_len = ft_strchr(s, c) - s;
			split[i++] = ft_substr(s, 0, w_len);
			s += w_len;
		}
	}
	split[i] = NULL;
	return (split);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	i;
		char	**split;

		split = ft_split(argv[1], argv[2][0]);
		i = 0;
		while (split[i] != 0)
		{
			printf("%s\n", split[i]);
			i++;
		}
	}
}
*/
