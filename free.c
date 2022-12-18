#include"push_swap.h"

void	ft_free(t_stack_list **stack_a)
{
	t_stack_list    *stack_a_clone;

	stack_a_clone = *stack_a;
	while (*stack_a && (*stack_a)->next)
	{
		stack_a_clone = (*stack_a)->next;
		free(*(stack_a));
		*stack_a = stack_a_clone;
	}
}

void	free_all(t_stack *stacks)
{
	t_stack_list *tmp;
	t_stack_list *tmp1;

	tmp = stacks->A;
	while (stacks->A)
	{
		stacks->A = stacks->A->next;
		free(tmp);
		tmp = stacks->A;
	}
	tmp1 = stacks->B;
	while (stacks->B)
	{
		stacks->B = stacks->B->next;
		free(tmp1);
		tmp1 = stacks->B;
	}
	free(stacks);
}
