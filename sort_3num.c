/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:45 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:53:47 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"include/push_swap.h"

int	max_value(t_stack_list *stack)
{
	int	highest;

	highest = stack->content;
	while (stack)
	{
		if (highest < stack->content)
			highest = stack->content;
		stack = stack->next;
	}
	return (highest);
}

void	sort_3num(t_stack	*stacks)
{
	t_stack_list	*tmp;

	tmp = stacks->a;
	if (check_sort(&stacks->a))
		return ;
	if (tmp->content == max_value(stacks->a) && !(check_sort(&stacks->a)))
		rotate(stacks, 'a');
	if (tmp->next->content == max_value(stacks->a) && !(check_sort(&stacks->a)))
		reverse_rotate(stacks, 'a');
	if (stacks->a->content > (stacks->a)->next->content
		&& !(check_sort(&stacks->a)))
		swap_stack(stacks, 'a');
	return ;
}
