/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:52:41 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 20:48:19 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (list_a && list_b && *list_a)
	{
		tmp = *list_a;
		*list_a = tmp->next;
		tmp->next = *list_b;
		*list_b = tmp;
	}
	write(1, "pb\n", 3);
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (list_a && list_b && *list_b)
	{
		tmp = *list_b;
		*list_b = tmp->next;
		tmp->next = *list_a;
		*list_a = tmp;
	}
	write(1, "pa\n", 3);
}
