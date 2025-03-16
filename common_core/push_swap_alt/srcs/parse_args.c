#include "../includes/push_swap.h"

static char	**argv_to_arr(int argc, char **argv)
{
	char	**arr;
	int		i;

	i = 1;
	arr = malloc(sizeof(char *) * argc);
	if (!arr)
		return (NULL);
	while (i < argc)
	{
		arr[i - 1] = ft_strdup(argv[i]);
		if (!arr[i - 1])
		{
			free_arr(arr);
			return (NULL);
		}
		i++;
	}
	arr[i - 1] = NULL;
	return (arr);
}

static void	numstr_to_node(char *numstr, t_list **lst)
{
	int	*num;
	t_list *node;

	num = malloc(sizeof(int));
	if (!num)
		error(lst);
	*num = ft_atoi(numstr);
	node = ft_lstnew(num);
	if (!node)
	{
		free(num);
		error(lst);
	}
	ft_lstadd_back(lst, node);
}

static t_list	*arr_to_list(char **arr)
{
	int	i;
	t_list	*lst;
	int	len;

	i = 0;
	lst = NULL;
	len = arr_len(arr);
	while (i < len)
	{
		if (is_number(arr[i]))
			numstr_to_node(arr[i], &lst);
		else
		{
			free_arr(arr);
			error(&lst);
		}
		i++;
	}
	free_arr(arr);
	return (lst);
}

t_list	*parse_args(int argc, char **argv)
{
	char	**argv_split;
	t_list	*lst;

	if (argc == 1)
		return (NULL);
	if (argc == 2)
		argv_split = split_cust(argv[1], " \t\n\r\v\f");
	else
		argv_split = argv_to_arr(argc, argv);
	lst = arr_to_list(argv_split);
	if (has_dups(lst))
		error(&lst);
	return (lst);
}