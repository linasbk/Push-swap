/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:19 by lsabik            #+#    #+#             */
/*   Updated: 2023/01/24 13:44:41 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_stack_list *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	swap_stack(t_stack *stacks, char var)
{
	if (var == 'a')
	{
		if (stacks->size < 2)
			return  ;
		ft_swap(stacks->a);
	}
	if (var == 'b')
	{
		if (!stacks->b)
			return  ;
		if (!(stacks->b)->next)
			return  ;
		ft_swap(stacks->b);
	}
	if (var == 's')
	{
		if (!stacks->b || !stacks->a)
			return  ;
		if (!(stacks->b)->next || !(stacks->a)->next)
			return  ;
		ft_swap(stacks->a);
		ft_swap(stacks->b);
	}
	return  ;
}

void	ft_push_b(t_stack *stacks)
{
	t_stack_list	*tmp;

	if (!(stacks->a))
		return  ;
	if (!stacks->b)
	{
		stacks->b = stacks->a;
		stacks->a = stacks->a->next;
		stacks->b->next = NULL;
	}
	else
	{
		tmp = stacks->b;
		stacks->b = stacks->a;
		stacks->a = stacks->a->next;
		stacks->b->next = tmp;
	}
	return  ;
}

void	ft_push_a(t_stack *stacks)
{
	t_stack_list	*tmp;

	if (!(stacks->b))
		return  ;
	if (!stacks->a)
	{
		stacks->a = stacks->b;
		stacks->b = stacks->b->next;
		stacks->a->next = NULL;
	}
	else
	{
		tmp = stacks->a;
		stacks->a = stacks->b;
		stacks->b = stacks->b->next;
		stacks->a->next = tmp;
	}
	return  ;
}
