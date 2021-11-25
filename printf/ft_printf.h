/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:10:32 by rtwitch           #+#    #+#             */
/*   Updated: 2021/11/25 20:45:23 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
//# include <stdio.h>

int	    ft_printf(const char *s, ...);
int     ft_strlen(const char *str);

void	ft_type(const char s, va_list *ap, int *j);
void    ft_putpointr(unsigned long n, int *j);
void	ft_putnbr_pointr(unsigned long n, int *j);
void	ft_putnbr_hex(unsigned int n, int *j, char s);
void	ft_putnbr(int n, int *j);
void	ft_putstr(char *s, int *j);
void	ft_putchar(char c, int *j);
void	ft_putnbr_u(unsigned int n, int *j);

#endif