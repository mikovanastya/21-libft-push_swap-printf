/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:28:20 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/23 16:33:31 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_max(t_list **list_a, t_list **list_b)
{
	int	rotate_a;
	int	rotate_b;

	sort_to_index(list_a);
	push_all_b(list_a, list_b);
	while (ft_len_list(list_b))
	{
		stack_b_flag(list_a, list_b);
		rotate_b = count_to_top(list_b, min_val_flag(list_b));
		rotate_a = count_to_top(list_a, closest_to_vl_in_a(list_a,
					min_val_flag(list_b)));
		ft_rotate_stack(list_a, list_b, rotate_a, rotate_b);
		pa(list_a, list_b);
	}
	ft_rotate_stack(list_a, list_b, count_to_top(list_a,
			value_by_index(list_a, 0)), 0);
}
