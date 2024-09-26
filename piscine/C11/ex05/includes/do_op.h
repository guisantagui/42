/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:55:37 by gsantama          #+#    #+#             */
/*   Updated: 2024/09/26 21:57:11 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
int		ft_sum(int n1, int n2);
int		ft_rest(int n1, int n2);
int		ft_mult(int n1, int n2);
int		ft_div(int n1, int n2);
int		ft_mod(int n1, int n2);
int		op_is_val(char *op);
int	(*ft_get_op(char op))(int, int);
void	do_op(int n1, int n2, char op);

#endif
