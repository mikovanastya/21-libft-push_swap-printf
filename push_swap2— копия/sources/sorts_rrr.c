/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:06:07 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 20:48:28 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	oper_reverse(t_list **list)
{
	t_list	*not_last;
	t_list	*last;

	if ((*list)->next != NULL)
	{
		last = *list;
		while (last->next)
		{
			if (last->next && !last->next->next)
				not_last = last;
			last = last->next;
		}
		last->next = *list;
		*list = last;
		not_last->next = 0;
	}
}

void	rra(t_list **list_a)
{
	oper_reverse(list_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **list_b)
{
	oper_reverse(list_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	oper_reverse(list_a);
	oper_reverse(list_b);
	write(1, "rrr\n", 4);
}
