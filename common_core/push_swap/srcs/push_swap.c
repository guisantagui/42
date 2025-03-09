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
	int	min;

	
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
		b = NULL;
		min = find_min(a);
		ft_printf("size_a before: %d\n", ft_lstsize(a));
		if (min < 0)
			subs_val(&a, min);
		ft_printf("minimum: %d\n", min);
		//swap(a);
		//rrotate(&a);
		//push(&a, &b);
		sort(&a, &b);
		ft_printf("size_a after sort: %d\n", ft_lstsize(a));
		//ft_printf("Hola");
		if (min < 0)
			add_val(&a, min);
		ft_printf("size_a after sort and add: %d\n", ft_lstsize(a));
		ft_printf("A:\n");
		print_list(a);
		ft_printf("B:\n");
		print_list(b);
		//ft_printf("%d\n", (*(int *)b->content));
		//b = b->next;
		//while (b)
		//	ft_printf("Je\n");
		
		//ft_printf("%d\n", (*(int *)b->content));
		/*while (b)
		{
			num = *(int *)b->content;
			ft_printf("B: %d\n", num);
			b = b->next;
		}*/
	}
	return (0);
}
