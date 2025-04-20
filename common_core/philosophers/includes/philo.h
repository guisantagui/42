#ifndef PHILO_H
# define PHILO_H

typedef struct s_table
{
    int n_philo;
	int t_to_die;
	int t_to_eat;
	int t_to_sleep;
	int n_t_each_philo_eat;
}   t_table;

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <pthread.h>

// Parser
t_table init_table(int argc, char **argv);

#endif