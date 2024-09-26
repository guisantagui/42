/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_is_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:22:16 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/26 21:48:28 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	op_is_val(char *op)
{
	int		i;
	char	all_ops[6];

	i = 0;
	ft_strcpy(all_ops, "+-*/%");
	if (ft_strlen(op) > 1)
		return (0);
	while (all_ops[i])
	{
		if (*op == all_ops[i])
			return (1);
		i++;
	}
	return (0);
}
