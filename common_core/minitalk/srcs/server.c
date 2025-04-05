/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:00:24 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/05 18:01:33 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../ft_printf/libft/libft.h"
#include <signal.h>

void	handler(int sig)
{
	static int			bit;
	static unsigned int	buffer;

	if (sig == SIGUSR1)
		buffer |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (unsigned char)buffer);
		bit = 0;
		buffer = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
	return (0);
}
