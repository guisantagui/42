/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:56:56 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/05 15:05:52 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(t_list *lst, char id, int *is_error)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->list = lst;
	stack->size = ft_lstsize(lst);
	stack->rank = get_list_ranks(lst, stack->size, is_error);
	if (*is_error == 1)
		return (NULL);
	stack->id = id;
	return (stack);
}

void	free_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	if (!(*stack)->list)
		ft_lstclear(&(*stack)->list, free);
	if (!(*stack)->rank)
		ft_lstclear(&(*stack)->rank, free);
	free(*stack);
	*stack = NULL;
}

void	free_ab(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

void	error_ab(t_stack **a, t_stack **b)
{
	free_ab(a, b);
	ft_printf("Error\n");
	exit(1);
}

void	error_stack(t_stack **s)
{
	free_stack(s);
	ft_printf("Error\n");
	exit(1);
}
