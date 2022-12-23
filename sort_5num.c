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

#include"include/push_swap.h"

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
int	find_pos(t_stack *stack)
{
	while (stack)
	{
		if (stack->content == min_value)
			min = stack->content;
		stack = stack->next;
	}
}

void	sort_5num(t_stack *stacks)
{
	int	size;
	int	old_max;
	int	pos;
	// int	new_max;

	pos = 0;
	size = min_value(stacks->a);
	printf("%d,",size,pos);
	// size = stacks->a->size;
	// while (size > 3 && !(check_sort(&stacks->a)))
	// {
	// 	ft_push_b(stacks);
	// 	size--;
	// }
	// if (size == 3 && !(check_sort(&stacks->a)))
	// 	sort_3num(stacks);
	// old_max = max_value(stacks->a);
	// if (check_sort(&stacks->a))
	// 	ft_push_a(stacks);
	// if (stacks->a->content == max_value(stacks->a) && stacks->a->content > old_max && !(check_sort(&stacks->a)))
	// 	reverse_rotate(stacks, 'a');
	// ft_push_a(stacks);
	// if (!(check_sort(&stacks->a)))
	// 	reverse_rotate(stacks, 'a');
}
