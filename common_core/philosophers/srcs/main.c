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
	t_table	table;
	//int	n_philo;
	//int	t_to_die;
	//int	t_to_eat;
	//int	t_to_sleep;
	//int	n_t_each_philo_eat;
	table = init_table(argc, argv);
	ft_printf("Number of philosophers: %d\n", table.n_philo);
	ft_printf("Time to die: %d\n", table.t_to_die);
	ft_printf("Time to eat: %d\n", table.t_to_eat);
	ft_printf("Time to sleep: %d\n", table.t_to_sleep);
	if (argc == 6)
		ft_printf("Number of times each philosopher has to eat: %d\n", table.n_t_each_philo_eat);
	return (0);
}
