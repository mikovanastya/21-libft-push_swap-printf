/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_steak.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:13:19 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/15 18:22:48 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	int				i;
	long long		result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}

int	fill_list(t_list *list, char *str)
{
	long long		inp_value;

	inp_value = ft_atoi(str);
	if (inp_value > INT_MAX || inp_value < INT_MIN)
		return (1);
	list->value = inp_value;
	list->index = -1;
	list->flag = 0;
	list->next = NULL;
	return (0);
}

t_list	*create_list(int argc, char **argv)
{
	t_list			*list;
	t_list			*tmp;
	int				i;

	i = 1;
	list = (t_list *)malloc(sizeof(t_list));
	tmp = list;
	if (fill_list(list, argv[i]))
		return (0);
	while (argc > 2)
	{
		i++;
		list->next = (t_list *)malloc(sizeof(t_list));
		list = list->next;
		if (fill_list(list, argv[i]))
			return (0);
		argc--;
	}
	return (tmp);
}
