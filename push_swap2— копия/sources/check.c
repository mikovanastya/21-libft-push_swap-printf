/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:36:47 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/24 17:24:17 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	ft_duplicate(t_list *list)
{
	t_list	*search;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (list)
	{
		search = list;
		while (search)
		{
			if (list->value == search->value)
				i++;
			search = search->next;
		}
		j++;
		list = list->next;
	}
	if (i != j)
		return (1);
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
