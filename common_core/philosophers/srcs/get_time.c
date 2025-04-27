#include "philo.h"

long    get_time(void)
{
    long    time;
    struct	timeval	tv;

    gettimeofday(&tv, NULL);
    time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time);
}

void    get_time_since_eat(t_philo_arg *philo)
{
    int left_fork;
    int right_fork;

    left_fork = philo->id;
    right_fork = (philo->id + 1) % philo->table->table_info.n_philo;
    while (1)
    {
        philo->time_since_eat += get_time() - philo->time_last_eat;
        usleep(10000);
        if (philo->time_since_eat >= (long)philo->table->table_info.t_to_die)
        {
            philo->table->philos[philo->id].is_dead = 1;
            break;
        }
        if (philo->table->forks[left_fork].is_locked == 0 && philo->table->forks[right_fork].is_locked == 0)
            break;
    }
}