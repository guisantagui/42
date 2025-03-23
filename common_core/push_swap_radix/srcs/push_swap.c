/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:23:48 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 21:07:27 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*init_data(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int	is_error;
	t_data	*data;

	is_error = 0;
	data = malloc(sizeof(t_data));
	a_stack = init_stack(parse_args(argc, argv), 'a', &is_error);
	if (is_error == 1)
	{
		free_stack(&a_stack);
		ft_printf("Error\n");
	}
	b_stack = init_stack(NULL, 'b', &is_error);
	if (is_error == 1)
		error_ab(&a_stack, &b_stack);
	data->a = a_stack;
	data->b = b_stack;
	return (data);
}

void	free_data(t_data **data)
{
	free_ab(&(*data)->a, &(*data)->b);
	free(*data);
	*data = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (0);
	else if (argc >= 2)
	{
		data = init_data(argc, argv);
		sort(&data, "RS");
		free_data(&data);
	}
	return (0);
}
