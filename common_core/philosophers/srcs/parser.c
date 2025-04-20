#include "philo.h"

void    free_table(t_table *table, char *msg)
{
    free(table);
    ft_printf(msg);
    exit(1);
}

void    error(char *msg)
{
    ft_printf(msg);
    exit(1);
}
/*
t_table *init_table(int argc, char **argv)
{
    t_table *table;

    if (argc >= 5 && argc <= 6)
	{
        table = malloc(sizeof(t_table));
        if (!table)
        {
            ft_printf("Alloc error\n");
            exit (1);
        }
        table->n_philo = ft_atoi(argv[1]);
		table->t_to_die = ft_atoi(argv[2]);
		table->t_to_eat = ft_atoi(argv[3]);
		table->t_to_sleep = ft_atoi(argv[4]);
        if (table->n_philo < 0 || table->t_to_die < 0
            || table->t_to_eat < 0 || table->t_to_sleep < 0)
            free_table(table, "Invalid argument(s)\n");
        if (argc == 6)
        {
			table->n_t_each_philo_eat = ft_atoi(argv[5]);
            if (table->n_t_each_philo_eat < 0)
                free_table(table, "Invalid argument(s)\n");
        }
        else
        {
            table->n_t_each_philo_eat = -42;
        }
        return (table);
    }
    return (NULL);
}
*/

t_table init_table(int argc, char **argv)
{
    t_table table;

    if (argc >= 5 && argc <= 6)
	{
        table.n_philo = ft_atoi(argv[1]);
		table.t_to_die = ft_atoi(argv[2]);
		table.t_to_eat = ft_atoi(argv[3]);
		table.t_to_sleep = ft_atoi(argv[4]);
        
        if (table.n_philo < 0 || table.t_to_die < 0
            || table.t_to_eat < 0 || table.t_to_sleep < 0)
            error("Invalid argument(s)\n");
        
        if (argc == 6)
        {
			table.n_t_each_philo_eat = ft_atoi(argv[5]);
            if (table.n_t_each_philo_eat < 0)
                error("Invalid argument(s)\n");
        }
        else
            table.n_t_each_philo_eat = -42;
        return (table);
    }
    else
    {
        exit (1);
    }
}