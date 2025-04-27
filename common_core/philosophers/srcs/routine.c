#include "philo.h"

static void philo_eat(t_philo_arg *philo)
{
    if (philo->table->any_deads == 0)
    {
        //printf("Time to eat for %d. any_deads: %d\n", philo->id, philo->table->any_deads);
        take_forks(&philo->table->philos[philo->id], philo->table);
        printf("%ld: %d has taken a fork\n", get_time() - philo->table->start_time, philo->id);
        printf("%ld: %d has taken a fork\n", get_time() - philo->table->start_time, philo->id);
        printf("%ld: %d is eating\n", get_time() - philo->table->start_time, philo->id);
        usleep(philo->table->table_info.t_to_eat * 1000);
        philo->table->philos[philo->id].times_eaten++;
        put_forks(&philo->table->philos[philo->id], philo->table);
        philo->time_last_eat = get_time();
        philo->time_since_eat = 0;
    }
}

static void philo_sleep(t_philo_arg *philo)
{
    if (philo->table->any_deads == 0)
    {
        //printf("Time to sleep for %d. any_deads: %d\n", philo->id, philo->table->any_deads);
        printf("%ld: %d is sleeping\n", get_time() - philo->table->start_time, philo->id);
        usleep(philo->table->table_info.t_to_sleep * 1000);
        philo->time_since_eat += philo->table->table_info.t_to_sleep;
    }
}

static void philo_think(t_philo_arg *philo)
{
    if (philo->table->any_deads == 0)
    {
        //printf("Time to think for %d. any_deads: %d\n", philo->id, philo->table->any_deads);
        printf("%ld: %d is thinking\n", get_time() - philo->table->start_time, philo->id);
    }
}

void    routine(void *arg)
{
    t_philo_arg *philo;
    int left_fork;
    int right_fork;

    philo = (t_philo_arg *)arg;
    philo->time_since_eat = 0;
    left_fork = philo->id;
    right_fork = (philo->id + 1) % philo->table->table_info.n_philo;
    while (1)
    {
        if (philo->table->any_deads == 1)
            break;
        get_time_since_eat(philo);
        if (philo->table->philos[philo->id].is_dead == 1)
        {
            printf("%ld: %d died\n", get_time() - philo->table->start_time, philo->id);
            break;
        }
        if (philo->table->forks[left_fork].is_locked == 0 && philo->table->forks[right_fork].is_locked == 0)
        {
            philo_eat(philo);
            philo_sleep(philo);
            philo_think(philo);
        }
    }
}