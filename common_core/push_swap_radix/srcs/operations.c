/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:57:28 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 21:01:37 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_list	*first;

	if (!src || !*src || !(*src)->rank)
		return ;
	first = (*src)->rank;
	(*src)->rank = first->next;
	first->next = NULL;
	ft_lstadd_front(&(*dst)->rank, first);
	(*src)->size--;
	(*dst)->size++;
	ft_printf("p%c\n", (*dst)->id);
}

void	swap(t_stack **stack)
{
	void	*t;

	if ((*stack)->rank && (*stack)->rank->next)
	{
		t = (*stack)->rank->content;
		(*stack)->rank->content = (*stack)->rank->next->content;
		(*stack)->rank->next->content = t;
		ft_printf("s%c\n", (*stack)->id);
	}
}

void	rotate(t_stack **stack)
{
	t_list	*first;
	t_list	*last;

	if ((*stack)->size > 1)
	{
		first = (*stack)->rank;
		last = (*stack)->rank;
		while (last -> next != NULL)
			last = last -> next;
		(*stack)->rank = first->next;
		first->next = NULL;
		last->next = first;
		ft_printf("r%c\n", (*stack)->id);
	}
}

void	rrotate(t_stack **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*sec_last;

	if ((*stack)->size > 1)
	{
		first = (*stack)->rank;
		last = (*stack)->rank;
		while (last -> next)
		{
			sec_last = last;
			last = last -> next;
		}
		last->next = first;
		(*stack)->rank = last;
		sec_last->next = NULL;
		ft_printf("rr%c\n", (*stack)->id);
	}
}
