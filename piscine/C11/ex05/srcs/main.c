/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:21:40 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/26 21:51:00 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char **argv)
{
	int		n1;
	int		n2;
	char	*op;
	char	op_c;

	if (argc == 4)
	{
		n1 = ft_atoi(argv[1]);
		n2 = ft_atoi(argv[3]);
		op = argv[2];
		if (op_is_val(op) == 0)
		{
			ft_putchar('0');
			ft_putchar('\n');
		}
		else
		{
			op_c = op[0];
			do_op(n1, n2, op_c);
		}
	}
	return (0);
}
