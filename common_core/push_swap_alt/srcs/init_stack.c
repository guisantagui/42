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