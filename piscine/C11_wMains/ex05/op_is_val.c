int     op_is_val(char *op)
{
        int     i;
        char    all_ops[5];

        i = 0;
        all_ops = "+-*/%";
        if (ft_strlen(op) > 1)
                return (0)
        while (all_ops[i])
        {
                if (op == all_ops[i])
                return (1);
        }
        return (0);
}
