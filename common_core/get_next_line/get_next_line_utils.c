/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:16:39 by gsantama          #+#    #+#             */
/*   Updated: 2025/01/13 18:17:45 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	out_len;	

	out_len = ft_strlen(s1) + 1;
	out = (char *)malloc(out_len * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, out_len);
	return (out);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (dst[len] && len < dstsize)
		len++;
	if (dstsize <= len)
		return (len + ft_strlen(src));
	while (src[i] != '\0' && (len + i + 1) < dstsize)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char const *s1, char const *s2, int free_both)
{
	int		len_s1;
	int		len_s2;
	int		len;
	char	*joined;

	if (!s1)
		s1 = "";
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2;
	joined = (char *)malloc((len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, len_s1 + 1);
	ft_strlcat(joined, s2, len + 1);
	if (s1 && *s1)
		free((void *)s1);
	if (s2 && free_both == 1)
		free((void *)s2);
	return (joined);
}
