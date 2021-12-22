/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:48:00 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 17:23:54 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	ft_dublicate(t_list *list)
{
	t_list	*stack;
	t_list	*search;

	stack = list;
	while (stack)
	{
		search = list;
		while (search)
		{
			if ((stack->value == search->value)
				&& (stack->index != search->index))
				return (1);
			search = search->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	validate_argc(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < 48 || str[i][j] > 57) && !(str[i][j] == 45))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
