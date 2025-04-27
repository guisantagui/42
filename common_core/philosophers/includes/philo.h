#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define THINK 0
# define EAT 1
# define SLEEP 2

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

// Structs philo
typedef struct s_table_info
{
    int n_philo;
	int t_to_die;
	int t_to_eat;
	int t_to_sleep;
	int n_t_each_philo_eat;
}   t_table_info;

typedef struct s_fork
{
	pthread_mutex_t fork;
	int	mutex_state;
	int	is_locked;
}	t_fork;

typedef struct s_philo
{
	pthread_t philo;
	int pthread_state;
	int	id;
	int	action;
	int	is_dead;
	int	times_eaten;
}	t_philo;

typedef struct s_table
{
	t_fork *forks;
	t_philo	*philos;
	t_table_info table_info;
	long	start_time;
}	t_table;

typedef struct s_philo_arg
{
	t_table *table;
	int id;
	int	left_fork;
	int	right_fork;
	long	time_since_eat;
	long	time_last_eat;
}	t_philo_arg;

// Parser
int	atoi_cust(const char *str, int *is_error);
t_table_info get_table_info(int argc, char **argv);

// Initialization
t_table *init_table(t_table_info table_info);

// Actions
void take_forks(t_philo *philo, t_table *table);
void put_forks(t_philo *philo, t_table *table);
void    routine(void *arg);

// Time
long    get_time(void);
void    get_time_since_eat(t_philo_arg *philo);

// Error handling
void    clean_table(t_table *table, char *msg, int end_prog);
void    error(char *msg);

#endif