#include "philo.h"

void    free_table(t_table_info *table_info, char *msg)
{
    free(table_info);
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

static void    check_table(t_table_info table_info)
{
    if (table_info.n_philo < 0 || table_info.t_to_die < 0
        || table_info.t_to_eat < 0 || table_info.t_to_sleep < 0)
        error("Error: Invalid argument(s)\n");
    if (table_info.n_philo < 1 || table_info.n_philo > 250)
        error("Error: Number of philosophers has to be between 1 and 250\n");
    if (table_info.t_to_sleep > table_info.t_to_die)
        error("Error: Time to sleep can't be larger than time to die");
    if (table_info.t_to_eat > table_info.t_to_die)
        error("Error: Time to eat can't be larger than time to die");
}

t_table_info get_table_info(int argc, char **argv)
{
    t_table_info table_info;
    int is_error;

    if (argc >= 5 && argc <= 6)
	{
        is_error = 0;
        table_info.n_philo = atoi_cust(argv[1], &is_error);
		table_info.t_to_die = atoi_cust(argv[2], &is_error);
		table_info.t_to_eat = atoi_cust(argv[3], &is_error);
		table_info.t_to_sleep = atoi_cust(argv[4], &is_error);
        check_table(table_info);
        if (argc == 6)
        {
			table_info.n_t_each_philo_eat = atoi_cust(argv[5], &is_error);
            if (table_info.n_t_each_philo_eat < 0)
                error("Error: Invalid argument(s)\n");
        }
        else
            table_info.n_t_each_philo_eat = -42;
        if (is_error == 1)
            error("Error: Arguments out of integer limits\n");
        return (table_info);
    }
    else
        exit (1);
}