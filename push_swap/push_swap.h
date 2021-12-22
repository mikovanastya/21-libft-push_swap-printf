/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:59:01 by rtwitch           #+#    #+#             */
/*   Updated: 2021/12/22 17:26:48 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include	<stdio.h>

typedef struct s_list{
    int				value;
	int				index;
	int				flag;
	struct s_list	*next;
}t_list;

t_list		*create_list(int argc, char **argv);
long long	ft_atoi(const char *str);

void		oper_swap(t_list **list);
void		sa(t_list **list_a);
void		sb(t_list **list_b);
void		ss(t_list **list_a, t_list **list_b);
void		oper_rotate(t_list **list);
void		ra(t_list **list);
void		rb(t_list **list);
void		rr(t_list **list_a, t_list **list_b);
void		oper_reverse(t_list **list);
void		rra(t_list **list_a);
void		rrb(t_list **list_b);
void		rrr(t_list **list_a, t_list **list_b);

void		ft_sort_two(t_list **list, int flag_list_b);
void		ft_sort_three_a(t_list **list);
void		ft_sort_three_b(t_list **list);
void		pa(t_list **list_a, t_list **list_b);
void		pb(t_list **list_a, t_list **list_b);
void		ft_sort_three_a(t_list **list);
void		ft_sort_three_b(t_list **list);
void		ft_sort_min(t_list **stack_a, t_list **stack_b);
void		b_to_a(t_list **list_a, t_list **list_b);
void		ft_sort_two(t_list **list, int flag_list_b);
void		sort_to_index(t_list **list);
void		find_to_middle(t_list **list);
void		push_all_b(t_list **list_a, t_list **list_b);
void		stack_b_flag(t_list **list_a, t_list **list_b);
void		ft_sort_max(t_list **list_a, t_list **list_b);
void		ft_rotate_stack(t_list **list_a, t_list **list_b, int r_a, int r_b);
void		print_all_stacks(t_list **stack_a, t_list **stack_b);

int			ft_abs(int a);
int			validate_argc(char **str);
int			count_to_top(t_list **list, int vl);
int			ft_sorted(t_list *list_a);
int			ft_len_list(t_list **list);
int			min_value(t_list **list);
int			max_value(t_list **list);
int			value_by_index(t_list **list, int i);
int			index_mediana(t_list **list);
int			ft_dublicate(t_list *list);
int			mediana_to_b(t_list	**list_a, t_list **list_b);
int			closest_to_vl_in_a(t_list **list_a, int vl);
int			min_val_flag(t_list **list_b);



#endif
