/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:56:42 by rtwitch           #+#    #+#             */
/*   Updated: 2021/11/25 20:53:54 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c, int *j)
{
	*j += write(1, &c, 1);
}

void	ft_putstr(char *s, int *j)
{
	if (!s)
		s = "(null)";
	*j += write (1, s, ft_strlen(s));
}

void	ft_putnbr(int n, int *j)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", j);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-', j);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, j);
			ft_putnbr(n % 10, j);
		}
		else
			ft_putchar(n + '0', j);
	}
}

void	ft_putnbr_u(unsigned int n, int *j)
{
	if (n < 0)
	{
		ft_putchar('-', j);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_u(n / 10, j);
		ft_putnbr_u(n % 10, j);
	}
	else
		ft_putchar(n + '0', j);
}
