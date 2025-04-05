/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:19:12 by gsantama          #+#    #+#             */
/*   Updated: 2025/04/05 15:07:44 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	numstr_to_node(char *numstr, t_list **lst, int *is_error)
{
	int		*num;
	t_list	*node;

	num = malloc(sizeof(int));
	if (!num)
	{
		*is_error = 1;
		return ;
	}
	*num = atoi_cust(numstr, is_error);
	node = ft_lstnew(num);
	if (!node || *is_error == 1)
	{
		*is_error = 1;
		free(num);
		return ;
	}
	ft_lstadd_back(lst, node);
}

static t_list	*arr_to_list(char **arr)
{
	int		i;
	t_list	*lst;
	int		len;
	int		*is_error;

	i = 0;
	lst = NULL;
	len = arr_len(arr);
	is_error = malloc(sizeof(int));
	*is_error = 0;
	while (i < len && *is_error == 0)
	{
		if (is_number(arr[i]))
			numstr_to_node(arr[i], &lst, is_error);
		else
			*is_error = 1;
		i++;
	}
	free_arr(arr);
	if (*is_error)
		error(&lst);
	free(is_error);
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
