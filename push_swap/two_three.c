/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:57:05 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/14 18:10:35 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list **list, int flag_list_b)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	second = first->next;
	if (first->value > second->value)
	{
		if (flag_list_b)
			sb(list);
		else
			sa(list);
	}
}

void	ft_sort_three_a(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *list;
	second = (*list)->next;
	third = (*list)->next->next;
	if (first->value > second->value && first->value > third->value)
	{
		ra(list);
		if (second->value > third->value)
			sa(list);
	}
	else if (first->value < second->value && first->value > third->value)
		rra(list);
	else if (first->value < second->value && second->value > third->value)
	{
		sa(list);
		if (first->value < third->value)
			ra(list);
	}
	else if (first->value > second->value && second->value < third->value)
		sa(list);
}

void	ft_sort_three_b(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *list;
	second = (*list)->next;
	third = (*list)->next->next;
	if (first->value > second->value && first->value > third->value)
	{
		rb(list);
		if (second->value > third->value)
			sb(list);
	}
	else if (first->value < second->value && first->value > third->value)
		rrb(list);
	else if (first->value < second->value && second->value > third->value)
	{
		sb(list);
		if (first->value < third->value)
			rb(list);
	}
	else if (first->value > second->value && second->value < third->value)
		sb(list);
}
