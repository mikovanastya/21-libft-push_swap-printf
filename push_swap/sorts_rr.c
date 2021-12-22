/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:34:19 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 17:24:53 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	oper_rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;

	if ((*list)->next != NULL)
	{
		last = *list;	
		first = *list;	
		while (last->next)
			last = last->next;
		last->next = first;
		*list = first->next;
		first->next = 0;
	}
}

void	ra(t_list **list_a)
{
	oper_rotate(list_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **list_b)
{
	oper_rotate(list_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **list_a, t_list **list_b)
{
	oper_rotate(list_a);
	oper_rotate(list_b);
	write(1, "rr\n", 3);
}
