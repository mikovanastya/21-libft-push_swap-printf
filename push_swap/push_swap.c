#include "push_swap.h"

void	print_stack(t_list **stack)
{
	t_list	*list;

	list = *stack;
	while (list)
	{
		printf("%p val = %d  [%d][%d] next - %p\n", list, list->value, list->index, list->flag, list->next);
		list = list->next;
	}
}

void print_all_stacks(t_list **stack_a, t_list **stack_b)
{
	printf("-A-\n");
	print_stack(stack_a);
	printf("-B-\n");
	print_stack(stack_b);
	printf("-------------\n");
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = create_list(argc, argv);
	print_all_stacks(&list_a, &list_b);
	if (!list_a)
	{
		printf("ERROR\n");
		return (1);
	}
	// if (ft_dublicate(list_a))
	// {
	// 	printf("ERROR\n");
	// 	return (1);
	// }
	// if (!ft_sorted(list_a))
	// 	return (0);
	print_stack(&list_a);
	//sort_to_index(&list_a);
	print_stack(&list_a);
	if (argc <= 7)
		ft_sort_min(&list_a, &list_b);
	else
	{
		ft_sort_max(&list_a, &list_b);
	}
	print_all_stacks(&list_a, &list_b);
}
