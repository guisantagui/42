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
	//int	num;

	
	if (argc == 1)
		return (0);
	else if (argc >= 2)
	{
		a = parse_args(argc, argv);
		if (!a || has_dups(a))
			error(&a);
		b = malloc(sizeof(t_list));
		if (!b)
		{
			ft_lstclear(&b, free);
			error(&a);
		}
		//ft_printf("Is sorted: %d\n", is_sorted(a));
		b = NULL;
		//sort_short(&a, &b, argc - 1, 0);
		quick_sort(&a, &b, argc - 1, 0);
		//ft_printf("A:\n");
		print_list(a);
	}
	return (0);
}
