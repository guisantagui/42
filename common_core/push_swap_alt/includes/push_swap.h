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

typedef struct s_stack
{
	t_list	*list;
    int     size;
	char	id;
}			t_stack;

// Parser
int	has_dups(t_list *list);
int	is_number(char *str);
int	arr_len(char **arr);
void free_arr(char **arr);
void    error(t_list **lst);
char	**split_cust(char *str, char *charset);
t_list  *parse_args(int argc, char **argv);

// Stack
t_stack	*init_stack(t_list *lst, char id);

// Operations
void    swap(t_list *lst);
void    rotate(t_list **lst);
void    rrotate(t_list **lst);
void    push(t_list **src, t_list **dst);
int find_min(t_list *lst, int len);
int find_max(t_list *lst, int len);
int is_sorted(t_list *lst, int reverse, int len);
int count_bits(int n);
void    sort_short(t_list **a, t_list **b, int len, int reverse);
void quick_sort(t_list **a, t_list **b, int len, int reverse);
void print_list(t_list *lst);

#endif
