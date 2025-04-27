#include "philo.h"

void take_forks(t_philo *philo, t_table *table)
{
    int left_fork;
    int right_fork;

    left_fork = philo->id;
    right_fork = (philo->id + 1) % table->table_info.n_philo;
    pthread_mutex_lock(&table->forks[left_fork].fork);
    table->forks[left_fork].is_locked = 1;
    //printf("%ld: %d has taken the left fork\n", get_time() - table->start_time, philo->id);
    pthread_mutex_lock(&table->forks[right_fork].fork);
    table->forks[right_fork].is_locked = 1;
    //printf("%ld: %d has taken the right fork\n", get_time() - table->start_time, philo->id);
    philo->action = EAT;
}

void put_forks(t_philo *philo, t_table *table)
{
    int left_fork;
    int right_fork;

    left_fork = philo->id;
    right_fork = (philo->id + 1) % table->table_info.n_philo;
    pthread_mutex_unlock(&table->forks[left_fork].fork);
    table->forks[left_fork].is_locked = 0;
    pthread_mutex_unlock(&table->forks[right_fork].fork);
    table->forks[right_fork].is_locked = 0;
    philo->action = THINK;
}