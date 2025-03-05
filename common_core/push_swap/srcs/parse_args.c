#include ¨push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] == '\0')
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_list	*parse_args(int argc, char **argv)
{
	int	i;
	t_list	*lst;
	t_list	*node;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		if (is_number(argv[i]))
		{
			node = ft_lstnew(ft_atoi(argv[i]));
			if (!node)
			{
				ft_lstclear(&lst, free);
				ft_printf("Error\n");
				exit(1);
			}
			ft_lstadd_back(&lst, node);
		}
		else
		{
			ft_printf("Error\n");
			ft_lstclear(&lst, free);
			exit(1);
		}
		i++;
	}
	return (lst);
}
