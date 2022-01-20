/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:02:58 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/23 15:41:42 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_to_index(t_list **list)
{
	int		min_value;
	int		i;
	t_list	*tmp;
	t_list	*min_list;

	i = 0;
	while (i < ft_len_list(list))
	{
		tmp = *list;
		min_value = INT_MAX;
		while (tmp)
		{
			if (tmp->value < min_value && tmp->index == -1)
			{
				min_list = tmp;
				min_value = tmp->value;
			}
			tmp = tmp->next;
		}
		min_list->index = i;
		i++;
	}
}

int	index_mediana(t_list **list)
{
	return ((ft_len_list(list) - 1) / 2 + 1);
}

int	value_by_index(t_list **list, int i)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->index == i)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
