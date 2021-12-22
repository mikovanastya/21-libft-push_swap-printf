/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_to_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:57:00 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 16:52:48 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_to_top(t_list **list, int vl)//кол-во оперрацийили чесел хз до нужного значения
{
	t_list	*tmp;
	int		count;
	int		after;

	tmp = *list;
	count = 0;
	while (tmp)
	{
		if (tmp->value == vl)
			break ;
		tmp = tmp->next;
		count++;
	}
	after = count - ft_len_list(list);
	if (count > ft_abs(after))
		return (after);
	else
		return (count);
}

int	closest_to_vl_in_a(t_list **list_a, int vl)// возвращает значение ближайшего ольшего соседа vl в стаке А
{
	t_list	*tmp;
	int		max;

	tmp = *list_a;
	max = INT_MAX;
	while (tmp)
	{
		if (tmp->value > vl && tmp->value < max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

void	stack_b_flag(t_list **list_a, t_list **list_b) //Считаем кол-во операций до верха В и + кол-во операций в стеке а
{
	t_list	*tmp;

	tmp = *list_b;
	while (tmp)
	{
		tmp->flag = ft_abs(count_to_top(list_b, tmp->value));
		tmp->flag += ft_abs(count_to_top(list_a, closest_to_vl_in_a(list_a, tmp->value)));
		tmp = tmp->next;
	}
}

int	min_val_flag(t_list **list_b)//миниммальное кол-во операций
{
	t_list	*tmp;
	int		min_flag;
	int		min_vl;

	min_flag = INT_MAX;
	tmp = *list_b;
	while (tmp)
	{
		if (tmp->flag < min_flag)
		{
			min_flag = tmp->flag;
			min_vl = tmp->value;
		}
		tmp = tmp->next;
	}
	return (min_vl);
}
