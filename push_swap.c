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
	if (var == 'a')
	{
		if (!stacks->A || !stacks->A->next)
			return ;
		ft_swap(stacks->A);
		write(1, "sa\n", 3);
	}
	if (var == 'b')
	{
		if (!stacks->B || !stacks->B->next)
			return ;
		ft_swap(stacks->B);
		write(1, "sb\n", 3);
	}
	if (var == 's')
	{
		if (!stacks->A || !stacks->A->next || !stacks->B || !stacks->B->next)
			return ;
		ft_swap(stacks->A);
		ft_swap(stacks->B);
		write(1, "ss\n", 3);
	}
}

void	ft_push_b(t_stack *stacks)
{
	t_stack_list	*tmp;

	if (!(stacks->A))
		return ; // FREE B
	if(!stacks->B)
	{
		stacks->B = stacks->A;
		stacks->A = stacks->A->next;
		stacks->B->next=NULL;
	}
	else
	{
		tmp = stacks->B;
		stacks->B = stacks->A;
		stacks->A = stacks->A->next;
		stacks->B->next = tmp;
	}
	write(1, "pb\n", 3);
	return ;
}

void	ft_push_a(t_stack *stacks)
{
	t_stack_list	*tmp;

	if(!(stacks->B))
		return ;
	if(!stacks->A)
	{
		stacks->A = stacks->B;
		stacks->B = stacks->B->next;
		stacks->A->next=NULL;
	}
	else
	{
		tmp = stacks->A;
		stacks->A = stacks->B;
		stacks->B = stacks->B->next;
		stacks->A->next = tmp;
	}
	write(1, "pa\n", 3);
	return ;
}
