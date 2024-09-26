/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:18:18 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/26 21:47:18 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	(*ft_get_op(char op))(int n1, int n2)
{
	char	all_ops[6];
	int		(*ops[6])(int, int);
	int		i;

	ft_strcpy(all_ops, "+-*/%");
	ops[0] = &ft_sum;
	ops[1] = &ft_rest;
	ops[2] = &ft_mult;
	ops[3] = &ft_div;
	ops[4] = &ft_mod;
	ops[5] = 0;
	i = 0;
	while (all_ops[i] != op && i < 5)
		i++;
	return (ops[i]);
}
