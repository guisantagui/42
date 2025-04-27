#include "philo.h"

static void clean_fork(t_fork *fork)
{
    if (fork != NULL)
    {
        if (fork->mutex_state == 0)
            pthread_mutex_destroy(&fork->fork);
        free(fork);
    }
}

void    clean_table(t_table *table, char *msg, int end_prog)
{
    int i;

    if (table != NULL)
    {
        i = 0;
        while (i < table->table_info.n_philo)
        {
            clean_fork(&table->forks[i]);
            
            i++;
        }
        if (table->philos != NULL)
            free(table->philos);
        free(table);
    }
    ft_printf(msg);
    if (end_prog == 1)
        exit(1);
}

void    error(char *msg)
{
    ft_printf(msg);
    exit(1);
}