/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:50:28 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/26 21:58:34 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	do_op(int n1, int n2, char op)
{
	int	res;

	if (op == '/' && n2 == 0)
		ft_putstr("Stop: division by zero");
	else if (op == '%' && n2 == 0)
		ft_putstr("Stop: modulo by zero");
	else
	{
		res = ft_get_op(op)(n1, n2);
		ft_putnbr(res);
		ft_putchar('\n');
	}
}
