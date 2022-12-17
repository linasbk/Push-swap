#include"push_swap.h"

void	ft_rotate(t_stack_list **stack)
{
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	*stack = (*stack)->next;
}

void	rotate(t_stack *stacks, char var)
{
	if (var == 'a')
	{
		if (!stacks->A)
			return ;
		ft_rotate(&stacks->A);
		write(1, "ra\n", 3);
	}
	if (var == 'b')
	{
		if (!stacks->B)
			return ;
		ft_rotate(&stacks->B);
		write(1, "rb\n", 3);
	}
	if (var == 's')
	{
		if (!stacks->B || !stacks->A)
			return ;
		ft_rotate(&stacks->A);
		ft_rotate(&stacks->B);
		write(1, "rr\n", 3);
	}
}

void	ft_reverse_rotate(t_stack_list **stack)
{
	t_stack_list	*tmp;

	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
}

void 	reverse_rotate(t_stack *stacks, char var)
{
	if (var == 'a')
	{
		if (!stacks->A)
			return ;
		ft_reverse_rotate(&stacks->A);
		write(1, "rra\n", 3);
	}
	if (var == 'b')
	{
		if (!stacks->B)
			return ;
		ft_reverse_rotate(&stacks->B);
		write(1, "rrb\n", 3);
	}
	if (var == 's')
	{
		if (!stacks->B || !stacks->A)
			return ;
		ft_reverse_rotate(&stacks->A);
		ft_reverse_rotate(&stacks->B);
		write(1, "rrr\n", 3);
	}
}