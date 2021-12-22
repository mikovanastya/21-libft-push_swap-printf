/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:02:58 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 17:30:45 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_index(t_list **list)// присваивает порядок 
{
	int		min_value;
	int		i;
	t_list	*tmp;
	t_list	*min_list;

	i = 0;
	while (i < ft_len_list(list))
	{
		tmp = *list;
		min_value = INT_MAX;
		while (tmp)
		{
			if (tmp->value < min_value && tmp->index == -1) // -1 неотсортированный лист++
			{
				min_list = tmp; //=>присваеваем начало 
				min_value = tmp->value;
			}
			tmp = tmp->next;
		}
		printf("min:  %d[%d]\n",min_value, i);
		min_list->index = i;
		i++;
	}
}

int	index_mediana(t_list **list)//индекс медианы
{
	return ((ft_len_list(list) - 1) / 2 + 1);
}

int value_by_index(t_list **list, int i)// значение по индексу
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->index == i)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

void ft_rotate_stack(t_list **list_a, t_list **list_b, int r_a, int r_b)//подается кол-во rotate - r_a, r_b))
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

/*
1. Находим мин, макс, медиану
2. Перекидываем медиану в В//
3. Перекидываем все элементы А (кроме мин макс) таким образом чтобы <mid слева а > справа от mid
ДО ТЕХ ПОР ПОКА НЕ ЗАКОНЧИТСЯ В
	4a. Считаем для каждого элемента В, сколько нужно шагов чтобы стать на нужное место в А
		4.1 Считаем кол-во операций до верха В
		4.2 Находим ближайшего большего соседа для элемента в А
		4.3 Считаем кол-во операций соседа А до верха в А
	4b Находим минимальный флаг по модулю (кол-во операций)
	4с Выполняем необходимые ротейты и пушим из В в А
5. Докручиваем стек А до отсортированного


min 0
max 9
mid 5

A: 0 8 1 7 4 9 2 5 3 6
rra rra rra pb
A: 6 3 0 8 1 7 4 9 2
B: 5

A: 0 9
B: 2 4 1 3 5 6 8 7
S: 2 3 4 5 6 5 4 3
ra pa 
A: 2 9 0
B: 4 1 3 5 6 8 7
S: 2 2 4 5 5 4 3
ra pa
A: 4 9 0 2
B: 1 3 5 6 8 7
S: 2 2 4 5 4 3
ra pa
A: 1 4 9 0 2
B: 3 5 6 8 7

А: 7 8 9 0 1 2 3 4 5 6

flag = если ra то + если rra то -



A1 0 3 6 10 12 13 15
FL 0 1 2 3  -3 -2 -1

B1 11 4 5 14 2 1  9   7  8
FL 0  1 2 3  4 -4 -3 -2 -1
*/


