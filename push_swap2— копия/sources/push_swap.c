/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:48:01 by rtwitch           #+#    #+#             */
/*   Updated: 2022/01/12 15:13:19 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atoi(const char *str)
{
	int				i;
	long long		result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}

int	fill_list(t_list *list, char *str)
{
	long long		inp_value;

	inp_value = ft_atoi(str);
	if (inp_value > INT_MAX || inp_value < INT_MIN)
	{
		write (1, "ERROR\n", 6);
		exit (1);
	}
	list->value = inp_value;
	list->index = -1;
	list->flag = 0;
	list->next = NULL;
	return (0);
}

t_list	*create_list(int argc, char **argv)
{
	t_list			*list;
	t_list			*tmp;
	int				i;

	i = 1;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		exit (0);
	tmp = list;
	if (fill_list(list, argv[i]))
		exit (0);
	while (argc > 2)
	{
		i++;
		list->next = (t_list *)malloc(sizeof(t_list));
		if (!(list->next))
			exit (0);
		list = list->next;
		if (fill_list(list, argv[i]))
			return (0);
		argc--;
	}
	return (tmp);
}

void	ft_free(t_list **list_a)
{
	t_list	*tmp;

	while ((*list_a)->next)
	{
		tmp = *list_a;
		*list_a = (*list_a)->next;
		free(tmp);
	}
	free(*list_a);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (0);
	if (validate_argc(argv))
	{
		write (1, "ERROR\n", 6);
		exit (1);
	}
	list_a = create_list(argc, argv);
	if (!list_a)
		return (0);
	if (ft_duplicate(list_a))
	{
		write (1, "ERROR\n", 6);
		exit (1);
	}
	if (ft_sorted(list_a))
		exit (0);
	if (argc <= 7)
		ft_sort_min(&list_a, &list_b);
	else
		ft_sort_max(&list_a, &list_b);
	ft_free (&list_a);
}
