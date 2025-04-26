/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:06:44 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/20 19:08:41 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table_info	table_info;
	t_table	*table;

	table_info = get_table_info(argc, argv);
	ft_printf("Number of philosophers: %d\n", table_info.n_philo);
	ft_printf("Time to die: %d\n", table_info.t_to_die);
	ft_printf("Time to eat: %d\n", table_info.t_to_eat);
	ft_printf("Time to sleep: %d\n", table_info.t_to_sleep);
	if (argc == 6)
		ft_printf("Number of times each philosopher has to eat: %d\n", table_info.n_t_each_philo_eat);
	table = malloc(sizeof(t_table));
	return (0);
}
