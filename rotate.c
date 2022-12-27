/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:28 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:53:30 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"include/push_swap.h"

void	ft_rotate(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*top;
	t_stack_list	*tail;

	tail = ft_lstlast(*stack);
	top = *stack;

	tmp = (*stack)->next;
	tail->next = top;
	top->next = NULL;
	(*stack) = tmp;
}

void	rotate(t_stack *stacks, char var)
{
	if (var == 'a')
	{
		if (!stacks->a)
			return ;
		ft_rotate(&stacks->a);
		write(1, "ra\n", 3);
	}
	if (var == 'b')
	{
		if (!stacks->b)
			return ;
		ft_rotate(&stacks->b);
		write(1, "rb\n", 3);
	}
	if (var == 's')
	{
		if (!stacks->b || !stacks->a)
			return ;
		ft_rotate(&stacks->a);
		ft_rotate(&stacks->b);
		write(1, "rr\n", 3);
	}
	return ;
}

void	ft_reverse_rotate(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*top;
	t_stack_list	*tail;

	tail = ft_lstlast(*stack);
	top = *stack;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	(*stack) = tail;
	(*stack)->next = top;
}

void	reverse_rotate(t_stack *stacks, char var)
{
	if (var == 'a')
	{
		if (!stacks->a)
			return ;
		ft_reverse_rotate(&stacks->a);
		write(1, "rra\n", 4);
	}
	if (var == 'b')
	{
		if (!stacks->b)
			return ;
		ft_reverse_rotate(&stacks->b);
		write(1, "rrb\n", 4);
	}
	if (var == 's')
	{
		if (!stacks->b || !stacks->a)
			return ;
		ft_reverse_rotate(&stacks->a);
		ft_reverse_rotate(&stacks->b);
		write(1, "rrr\n", 4);
	}
	return ;
}
