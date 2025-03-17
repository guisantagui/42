/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:23:48 by gsantama          #+#    #+#             */
/*   Updated: 2025/03/17 19:25:33 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", (*(int *)lst->content));
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_listi	*a;
	t_list	*b;
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (argc == 1)
		return (0);
	else if (argc >= 2)
	{
		a = parse_args(argc, argv);
		b = malloc(sizeof(t_list));
		if (!b)
		{
			ft_lstclear(&b, free);
			error(&a);
		}
		b = NULL;
		a_stack = init_stack(a, 'a');
		b_stack = init_stack(b, 'b');
		quick_sort(&a_stack, &b_stack, a_stack->size, 0);
		free_ab(&a_stack, &b_stack);
	}
	return (0);
}
