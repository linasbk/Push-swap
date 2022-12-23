/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:19 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:53:20 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"include/push_swap.h"

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
		if (!stacks->a || !stacks->a->next)
			return ;
		ft_swap(stacks->a);
		write(1, "sa\n", 3);
	}
	if (var == 'b')
	{
		if (!stacks->b || !stacks->b->next)
			return ;
		ft_swap(stacks->b);
		write(1, "sb\n", 3);
	}
	if (var == 's')
	{
		if (!stacks->a || !stacks->a->next || !stacks->b || !stacks->b->next)
			return ;
		ft_swap(stacks->a);
		ft_swap(stacks->b);
		write(1, "ss\n", 3);
	}
	return ;
}

void	ft_push_b(t_stack *stacks)
{
	t_stack_list	*tmp;

	if (!(stacks->a))
		return ; // FREE B
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
	write(1, "pb\n", 3);
	return ;
}

void	ft_push_a(t_stack *stacks)
{
	t_stack_list	*tmp;

	if (!(stacks->b))
		return ;
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
	write(1, "pa\n", 3);
	return ;
}
