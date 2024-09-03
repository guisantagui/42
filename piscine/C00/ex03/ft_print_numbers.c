/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:01:36 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/03 20:02:36 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int		num;
	char	to_out;

	num = 0;
	while (num <= 9)
	{
		to_out = num + '0';
		write (1, &to_out, 1);
		num++;
	}
}
