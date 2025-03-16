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