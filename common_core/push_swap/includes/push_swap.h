#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"

int	has_dups(t_list *list);
t_list  *parse_args(int argc, char **argv);
void    error(t_list **lst);
void    swap(t_list *lst);
void    rotate(t_list **lst);
void    rrotate(t_list **lst);
void    push(t_list **src, t_list **dst);

#endif
