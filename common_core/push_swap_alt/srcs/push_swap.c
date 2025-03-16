#include "../includes/push_swap.h"

void	print_list(t_list *lst){
	while (lst)
	{
		ft_printf("%d\n", (*(int *)lst->content));
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_stack *a_stack;
	t_stack *b_stack;

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
		sort_short(&a_stack->list, &b_stack->list, a_stack->size, 0);
		//sort_short(&a, &b, argc - 1, 0);
		quick_sort(&a, &b, argc - 1, 0);
		//ft_printf("A:\n");
		//print_list(a_stack->list);
		print_list(a);
		//ft_printf("Is sorted: %d\n", is_sorted(a, 0, ft_lstsize(a)));
	}
	return (0);
}
