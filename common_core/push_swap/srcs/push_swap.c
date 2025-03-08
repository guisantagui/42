#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int	num;

	
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
		swap(a);
		rrotate(&a);
		push(&a, &b);
		while (a)
		{
			num = *(int *)a->content;
			ft_printf("A: %d\n", num);
			a = a->next;
		}
		while (b)
		{
			num = *(int *)b->content;
			ft_printf("B: %d\n", num);
			b = b->next;
		}
	}
	return (0);
}
