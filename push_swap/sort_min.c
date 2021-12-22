/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:11:15 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/17 20:05:12 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_list(t_list **list)
{
	t_list	*tmp;
	int		len;

	len = 0;
	if (!list && !*list)
		return (0);
	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	//printf ("%d\n", len);
	return (len);
}

void	ft_sort_min(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = ft_len_list(stack_a);
	if (ft_len_list(stack_a) >= 4)
	{	
		while (ft_len_list(stack_a) != 3)
			pb(stack_a, stack_b);
		ft_sort_three_a(stack_a);
		if (ft_len_list(stack_b) == 3)
			ft_sort_three_b(stack_b);
		else if (ft_len_list(stack_b) == 2)
			ft_sort_two(stack_b, 1);
		b_to_a(stack_a, stack_b);
	}
	else if (len_a == 3)
		ft_sort_three_a(stack_a);
	else if (len_a == 2)
		ft_sort_two(stack_a, 0);
}

void	b_to_a(t_list **list_a, t_list **list_b)
{
	int	len;
	int	i;

	len = ft_len_list(list_a);
	i = 0;
	while (i < len)
	{
		if (*list_b && (*list_a)->value > (*list_b)->value)
		{
			pa(list_a, list_b);
			len++;
		}
		i++;
		ra(list_a);
	}
	while (*list_b)
	{
		pa(list_a, list_b);
		ra(list_a);	
	}
}
