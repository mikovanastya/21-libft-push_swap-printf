/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:29:21 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 20:48:32 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	oper_swap(t_list **list)
{
	t_list	*tmp;

	if ((*list)->next != NULL)
	{
		tmp = (*list)->next;
		(*list)->next = (*list)->next->next;
		tmp->next = (*list);
		(*list) = tmp;
		tmp = NULL;
	}
}

void	sa(t_list **list_a)
{
	oper_swap(list_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **list_b)
{
	oper_swap(list_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **list_a, t_list **list_b)
{
	oper_rotate(list_a);
	oper_rotate(list_b);
	write(1, "ss\n", 3);
}
