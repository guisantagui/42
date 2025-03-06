#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list *a;
	int	num;

	if (argc == 1)
		return (0);
	else if (argc >= 2)
	{
		a = parse_args(argc, argv);
		if (!a || has_dups(a))
			error(&a);
		swap(a);
		rrotate(&a);
		while (a)
		{
			num = *(int *)a->content;
			ft_printf("%d\n", num);
			a = a->next;
		}
	}
	return (0);
}
