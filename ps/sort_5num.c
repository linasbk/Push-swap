/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:45 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:53:47 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	min_value(t_stack_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	find_pos(t_stack_list *stack, int min)
{
	int				pos;

	pos = 0;
	min = min_value(stack);
	while (stack)
	{
		if (stack->content == min)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	sort_5num(t_stack *stacks)
{
	int				size;
	int				min;
	t_stack_list	*tmp;

	tmp = stacks->a;
	size = stacks->a->size;
	while (size != 3)
	{
		min = min_value(stacks->a);
		while (tmp->content != min)
		{
			if (find_pos(stacks->a, min) >= (size / 2))
				reverse_rotate(stacks, 'a');
			else
				rotate(stacks, 'a');
			tmp = stacks->a;
		}
		ft_push_b(stacks);
		size--;
	}
	sort_3num(stacks);
	while (stacks->b)
		ft_push_a(stacks);
}
