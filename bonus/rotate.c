/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:28 by lsabik            #+#    #+#             */
/*   Updated: 2023/01/24 13:44:41 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
		if (!(stacks->a))
			return  ;
		if (!(stacks->a)->next)
			return  ;
		ft_rotate(&stacks->a);
	}
	if (var == 'b')
	{
		if (!stacks->b)
			return  ;
		if (!(stacks->b)->next)
			return  ;
		ft_rotate(&stacks->b);
	}
	if (var == 's')
	{
		if (!stacks->b || !stacks->a)
			return  ;
		if (!(stacks->b)->next || !(stacks->a)->next)
			return  ;
		ft_rotate(&stacks->a);
		ft_rotate(&stacks->b);
	}
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
			return  ;
		if (!(stacks->a)->next)
			return  ;
		ft_reverse_rotate(&stacks->a);
	}
	if (var == 'b')
	{
		if (!stacks->b)
			return  ;
		if (!(stacks->b)->next)
			return  ;
		ft_reverse_rotate(&stacks->b);
	}
	if (var == 's')
	{
		if (!stacks->b || !stacks->a)
			return  ;
		if (!(stacks->b)->next || !(stacks->a)->next)
			return  ;
		ft_reverse_rotate(&stacks->a);
		ft_reverse_rotate(&stacks->b);
	}
}
