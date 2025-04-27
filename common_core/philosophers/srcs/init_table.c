#include "philo.h"

static void fill_table(t_table *table, t_table_info table_info)
{
    int i;

    i = 0;
    while (i < table_info.n_philo)
    {
        table->forks[i].mutex_state = pthread_mutex_init(&table->forks[i].fork, NULL);
        if (table->forks[i].mutex_state != 0)
            clean_table(table, "Error: fork init failed\n", 1);
        table->forks[i].is_locked = 0;
        table->philos[i].id = i;
        table->philos[i].action = THINK;
        table->philos[i].is_dead = 0;
        table->philos[i].times_eaten = 0;
        i++;
    }
    table->any_deads_mutex_state = pthread_mutex_init(&table->any_deads_mutex, NULL);
    if (table->any_deads_mutex_state != 0)
        clean_table(table, "Error: any deads mutex init failed\n", 1);
}

t_table *init_table(t_table_info table_info)
{
    t_table *table;

    table = malloc(sizeof(t_table));
    if (!table)
        error("Error: table allocation error\n");
    table->forks = malloc(sizeof(t_fork) * table_info.n_philo);
    if (!table->forks)
    {
        free(table);
        error("Error: fork allocation error\n");
    }
    table->philos = malloc(sizeof(t_philo) * table_info.n_philo);
    if (!table->philos)
    {
        free(table->forks);
        free(table);
        error("Error: fork allocation error\n");
    }
    fill_table(table, table_info);
    table->table_info = table_info;
    table->start_time = get_time();
    return(table);
}