/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:14:25 by rtwitch           #+#    #+#             */
/*   Updated: 2021/11/25 19:07:04 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <unistd.h>
// #include <stdarg.h>
// #include <stdio.h>

void	ft_putnbr_hex(unsigned int n, int *j, char s)
{
	char	*base;
	char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (n < 16)
	{
		if (s == 'x')
			ft_putchar(base[n], j);
		if (s == 'X')
			ft_putchar(base2[n], j);
	}
	else
	{
		ft_putnbr_hex(n / 16, j, s);
		ft_putnbr_hex(n % 16, j, s);
	}
}

void	ft_putnbr_pointr(unsigned long n, int *j)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
	{
		ft_putchar(base[n], j);
	}
	else
	{
		ft_putnbr_pointr(n / 16, j);
		ft_putnbr_pointr(n % 16, j);
	}
}
void ft_putpointr(unsigned long n, int *j)
{
	ft_putchar('0', j);
	ft_putchar('x', j);
	ft_putnbr_pointr(n, j);
}

void	ft_type(const char s, va_list *ap, int *j)
{
	if (s == 'c')
		ft_putchar(va_arg(*ap, int), j);
	else if (s == 's')
		ft_putstr(va_arg(*ap, char *), j);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*ap, int), j);
	else if (s == 'u')
		ft_putnbr(va_arg(*ap, unsigned int), j);
	else if (s == 'p')
		ft_putpointr(va_arg(*ap, unsigned long), j);
	else if (s == 'x' || s == 'X')
		ft_putnbr_hex(va_arg(*ap, unsigned int), j, s);
	else if (s == '%')
	 	ft_putchar('%', j);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		j;	

	i = 0;
	j = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_type(s[i], &ap, &j);
		}
		else
			ft_putchar(s[i], &j);
		i++;
	}
	va_end(ap);
	return (j);
}

// int	main(void)
// {
// 	char a;
// 	int my_f;
// 	int orig;

// 	a = 0;
// 	my_f = 0;
// 	orig = 0;
// 	// my_f = ft_printf("AAAA %c %c %c \n", 'Z', 'z', 'Z');
// 	// orig = printf("BBBB %c %c %c \n", 'Z', 'z', 'Z');
// 	// my_f = ft_printf("AAAA    %s  %p\n", "qwe", 113);
// 	// orig = printf("AAAA    %s  %p\n", "qwe", 113);
// 	// my_f = ft_printf("AAAA    %d %d %d\n", 123456, 12, a);
// 	// orig = printf("BBBB    %d %d %d\n", 123456, 12, a);
// 	// my_f = ft_printf("AAAA    %u %u %u\n", 123456, 12, a);
// 	// orig = printf("BBBB    %u %u %u\n", 123456, 12, a);
// 	// my_f = ft_printf("AAAA    %p %p %p \n", &a, &a, 0);
// 	// orig = printf("BBBB    %p %p %p \n", &a, &a, 0);
// 	// my_f = ft_printf("AAAA    %x %x %x\n", 123456, 12, a);
// 	// orig = printf("BBBB    %x %x %x\n", 123456, 12, a);
// 	my_f = ft_printf("AAAA    %X %X %X\n", 123456, 12, a);
// 	orig = printf("BBBB    %X %X %X\n", 123456, 12, a);
// 	printf("\nmy_f: %d\norig: %d", my_f, orig);
// 	return 0;
// }