/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:56:27 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/05 17:59:54 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../ft_printf/libft/libft.h"
#include <signal.h>

void	handler(int sig, siginfo_t *info, void *context)
{
	static int			bit;
	static unsigned int	buffer;

	(void) context;
	if (sig == SIGUSR1)
		buffer |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (unsigned char)buffer);
		if ((unsigned char)buffer == '\n')
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		buffer = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &handler;
	sigact.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR2, &sigact, NULL);
	sigaction(SIGUSR1, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
