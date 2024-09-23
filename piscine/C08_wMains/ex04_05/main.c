#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int	main(int argc, char **argv)
{
	t_stock_str	*out_stock;

	out_stock = ft_strs_to_tab(argc - 1, argv + 1);
	ft_show_tab(out_stock);
}
