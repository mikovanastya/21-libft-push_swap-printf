/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:06:48 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 17:07:10 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mediana_to_b(t_list	**list_a, t_list **list_b)//меняет пушит
{
	int	i;
	int	vl_medi;
	int	ind_medi;
	int steps;

	i = 0;
	ind_medi = index_mediana(list_a);
	vl_medi = value_by_index(list_a, ind_medi);
	steps = count_to_top(list_a, vl_medi);
	if (steps > 0)
	{
		while (i++ < ft_abs(steps))
			ra(list_a);
	}
	else if (steps < 0)
	{
		while (i++ < ft_abs(steps))
			rra(list_a);
	}
	pb(list_a, list_b);
	return (vl_medi);
}

void	push_all_b(t_list **list_a, t_list **list_b)//перекидывем все кроме min max med
{
	t_list	*tmp_a;
	int		tmp_b;
	int		min;
	int		max;
	int		mediana;

	min = value_by_index(list_a, 0);
	max = value_by_index(list_a, ft_len_list(list_a) - 1);
	mediana = mediana_to_b(list_a, list_b);
	while (ft_len_list(list_a) > 2)
	{
		tmp_a = (*list_a);
		if (tmp_a->value != min && tmp_a->value != max)
		{
			pb(list_a, list_b);
			if (tmp_a->value > mediana)
				rb(list_b);
		}
		else
			ra(list_a);
	}
}
