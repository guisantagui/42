/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:25:44 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/20 19:12:15 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define EVEN(n) ((n) % 2 == 0)

typedef int t_bool;
#define TRUE 1
#define FALSE 0
void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);
