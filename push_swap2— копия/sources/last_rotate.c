/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:03:12 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/23 16:35:19 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_ra(t_list **list_a, int r_a)
{	
	while (r_a != 0)
	{
		if (r_a > 0)
		{
			ra(list_a);
			r_a--;
		}
		else
		{
			rra(list_a);
			r_a++;
		}
	}
}

void	rotate_rb(t_list **list_b, int r_b)
{
	while (r_b != 0)
	{
		if (r_b > 0)
		{
			rb(list_b);
			r_b--;
		}
		else
		{
			rrb(list_b);
			r_b++;
		}
	}
}

void	ft_rotate_stack(t_list **list_a, t_list **list_b, int r_a, int r_b)
{
	while (r_a > 0 && r_b > 0)
	{
		rr(list_a, list_b);
		r_a--;
		r_b--;
	}
	while (r_a < 0 && r_b < 0)
	{
		rrr(list_a, list_b);
		r_a++;
		r_b++;
	}
	rotate_ra(list_a, r_a);
	rotate_rb(list_b, r_b);
}
