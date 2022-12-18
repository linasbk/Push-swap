#include"push_swap.h"

int check_sort(t_stack_list **stack)
{
	t_stack_list *tmp;

	tmp = *stack;
	while (*stack && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	ft_free(stack);
	return (0);
}
