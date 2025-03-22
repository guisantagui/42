#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN (-2147483648)
# endif

typedef struct	s_stack
{
	t_list	*list;
	t_list	*rank;
	int	size;
	char	id;
}		t_stack;

typedef struct	s_stack_state
{
	int	error;
	int	pivot;
	int	first_content;
	int	first_content_set;
	int	content_less;
	int	n_rotations;
}		t_stack_state;

// Parser
int	has_dups(t_list *list);
int	is_number(char *str);
int	arr_len(char **arr);
int	atoi_cust(const char *str, int *is_error);
void	free_arr(char **arr);
void	error(t_list **lst);
char	**split_cust(char *str, char *charset);
t_list	*parse_args(int argc, char **argv);

// Stack
t_stack	*init_stack(t_list *lst, char id, int *is_error);
void	free_stack(t_stack **stack);
void	free_ab(t_stack **a, t_stack **b);
t_list *get_list_ranks(t_list *lst, int size, int *is_error);
void	error_ab(t_stack **a, t_stack **b);

// Operations
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
int	find_min(t_list *lst, int len);
int	find_max(t_list *lst, int len);

// Sort
int	is_sorted(t_list *lst, int reverse, int len);
void	sort_two(t_stack **stack, int len, int reverse);
void    sort_three(t_stack **stack, int len, int reverse);
void	sort_four(t_stack **a, t_stack **b, int len, int reverse);
void	sort_five(t_stack **a, t_stack **b, int len, int reverse);
void	sort_short(t_stack **a, t_stack **b, int len, int reverse);
void    radix_sort(t_stack **a, t_stack **b);

void	bubblesort(int *arr, int len);
int	get_pivot(t_list *lst, int len, int *is_error);
t_stack_state	init_state(t_stack **a, t_stack **b, int len);
t_stack_state	do_partition(t_stack **a, t_stack **b, int len, int reverse);
void	reset_stacks(t_stack **a, t_stack **b, t_stack_state state);
void	quick_sort(t_stack **a, t_stack **b, int len, int reverse);
void    sort(t_stack **a, t_stack **b, char *alg);
void	print_list(t_list *lst);

#endif
