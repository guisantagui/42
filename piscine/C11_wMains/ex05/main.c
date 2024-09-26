int	main(int argc, char **argc)
{
	if (argc == 4)
	{
		int	n1;
		int	n2;
		char	op;
		int	res;

		n1 = ft_atoi(argv[1]);
		n2 = ft_atoi(argv[3]);
		op = argv[2];
		if (op_is_val(op) == 0)
			ft_putchar('0');
			ft_putchar('\n');
		else
		{
			if (op == '/' && n2 == 0)
				ft_putstr("Stop: division by zero");
			else if (op == '%' && n2 == 0)
				ft_putstr("Stop: modulo by zero");
			else
			{
				res = ft_get_op(op)(n1, n2);
				ft_putnbr(res);
				ft_putchar('\n');
			}	
		}
	}
	return (0);
}
