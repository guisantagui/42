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
	t_philo_arg	*philos;
	int		i;

	table_info = get_table_info(argc, argv);
	ft_printf("Number of philosophers: %d\n", table_info.n_philo);
	ft_printf("Time to die: %d\n", table_info.t_to_die);
	ft_printf("Time to eat: %d\n", table_info.t_to_eat);
	ft_printf("Time to sleep: %d\n", table_info.t_to_sleep);
	if (argc == 6)
		ft_printf("Number of times each philosopher has to eat: %d\n", table_info.n_t_each_philo_eat);
	table = init_table(table_info);
	ft_printf("Action: %d\n", table->philos[0].action);
	philos = malloc(sizeof(t_philo_arg) * table_info.n_philo);
	if (!philos)
		clean_table(table, "Error: philosophers allocation failed\n", 1);
	i = 0;
	while (i < table_info.n_philo)
	{
		philos[i].table = table;
		philos[i].id = i;
		philos[i].time_since_eat = 0;
		philos[i].time_last_eat = get_time();
		pthread_create(&table->philos[i].philo, NULL, (void *)routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < table_info.n_philo)
	{
		pthread_join(table->philos[i].philo, NULL);
		i++;
	}
	//clean_table(table, "", 0);
	free(philos);
	return (0);
}
