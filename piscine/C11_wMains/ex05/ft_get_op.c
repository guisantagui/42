int	(*ft_get_op(char op))(int, int)
{
	char	all_ops[5];
	int	(*ops[5])(int, int);
	int	i;

	all_ops = "+-*/%";
	ops = {ft_sum, ft_rest, ft_mult, ft_div, ft_mod}
	i = 0;
	while (all_ops[i] != op)
		i++;
	return (&ops[i])
}
