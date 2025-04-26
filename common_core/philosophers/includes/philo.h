#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <pthread.h>

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
	int	is_locked;
}	t_fork;

typedef struct s_philo
{
	int	action;
	int	is_dead;
}	t_philo;

typedef struct s_table
{
	t_fork *forks;
	t_philo	*philo;
}	t_table;

// Parser
int	atoi_cust(const char *str, int *is_error);
t_table_info get_table_info(int argc, char **argv);

#endif