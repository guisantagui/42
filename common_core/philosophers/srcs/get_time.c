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
        //pthread_mutex_lock(&philo->table->any_dead_mutex);
        if (philo->table->any_dead == 1)
        {
            //pthread_mutex_unlock(&philo->table->any_dead_mutex);
            break;
        }
        //pthread_mutex_unlock(&philo->table->any_dead_mutex);
        philo->time_since_eat += get_time() - philo->time_last_eat;
        usleep(10000);
        /*
        pthread_mutex_lock(&philo->table->any_dead_mutex);
        
        if (philo->table->any_dead == 1)
        {
            pthread_mutex_unlock(&philo->table->any_dead_mutex);
            break;
        }
        pthread_mutex_unlock(&philo->table->any_dead_mutex);
        */
        if (philo->time_since_eat >= (long)philo->table->table_info.t_to_die)
        {
            printf("Philo %d:: Time since eat: %ld. Time to die: %d\n", philo->id, philo->time_since_eat, philo->table->table_info.t_to_die);
            philo->table->philos[philo->id].is_dead = 1;
            //pthread_mutex_lock(&philo->table->any_dead_mutex);
            philo->table->any_dead = 1;
            //pthread_mutex_unlock(&philo->table->any_dead_mutex);
            break;
        }
        if (philo->table->forks[left_fork].is_locked == 0 && philo->table->forks[right_fork].is_locked == 0)
            break;
    }
}