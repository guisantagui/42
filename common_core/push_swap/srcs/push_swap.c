#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *a;
	if (argc == 1)
	{
		return (0)
	}
	else if (argc >= 2)
	{
		a = parse_args(*argv);
		if (!a || has_dups(a))
		{
			ft_lstclear(&a, free);
			ft_printf("Error\n");
			exit(1);
		}
	}
	return (0);
}
