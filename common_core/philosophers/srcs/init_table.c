#include "philo.h"

void init_table(t_table_info table_info, t_table *table)
{
    table->forks = malloc(sizeof(t_fork) * table_info.n_philo);
    if (!table->forks)
    table->philo = malloc(sizeof(t_philo) * table_info.n_philo);
}