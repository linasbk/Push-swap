#include"push_swap.h"

void    ft_swap(t_stack_list *stack)
{
    int tmp;

    tmp = stack->content;
    stack->content = stack->next->content;
	stack->next->content = tmp;
}

void    swap_stack(t_stack *stacks, char var)
{
	if (!stacks->A || !stacks->A->next)
		ft_error();
	if (var == 'a')
	{
		ft_swap(stacks->A);
		write(1, "sa\n", 3);
	}
	if (var == 'b')
	{
		ft_swap(stacks->B);
		write(1, "sb\n", 3);
	}
	if (var == 's')
	{
		ft_swap(stacks->A);
		ft_swap(stacks->B);
		write(1, "ss\n", 3);
	}
}

void	ft_push_a(t_stack *stacks)
{
	t_stack_list	*tmp;
	if(!*stack_b)
		exit(EXIT_FAILURE);
	if(!*stack_a)
	{
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next=NULL;
	}
	else
	{
		tmp = *stack_a;
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = tmp;
	}
	write(1, "pa\n", 3);
	return ;
}

void	ft_push_a(t_stack *stacks)
{
	t_list *tmp;
	if(!*stack_b)
		exit(EXIT_FAILURE);
	if(!*stack_a)
	{
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next=NULL;
	}
	else
	{
		tmp = *stack_a;
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = tmp;
	}
	write(1, "pa\n", 3);
	return ;
}
