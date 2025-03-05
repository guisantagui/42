/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:49:20 by gsantama          #+#    #+#             */
/*   Updated: 2025/01/11 15:25:06 by gsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(int nbr, char *base, int sig);
int		ft_putptr(unsigned long p);

#endif
