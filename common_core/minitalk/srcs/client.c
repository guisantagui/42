/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:54:06 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/05 17:56:06 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../ft_printf/libft/libft.h"
#include <signal.h>

void	send_char(int pid, unsigned char oct)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((oct & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(200);
	}
}

void	send_argv(char **argv)
{
	int	pid;
	int	i;

	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, (unsigned char)argv[2][i]);
		i++;
	}
	send_char(pid, (unsigned char) '\n');
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_argv(argv);
	return (0);
}
