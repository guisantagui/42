/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:56:56 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 20:57:12 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(t_list *lst, char id)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->list = lst;
	stack->size = ft_lstsize(lst);
	stack->id = id;
	return (stack);
}

static void	free_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	if (!(*stack)->list)
		ft_lstclear(&(*stack)->list, free);
	free(*stack);
	*stack = NULL;
}

void	free_ab(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}
