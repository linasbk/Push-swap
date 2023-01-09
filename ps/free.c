/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:52:36 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:52:39 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_list *stack)
{
	t_stack_list	*tmp;

	tmp = stack;
	while (stack)
	{
		stack = stack->next;
		free(tmp);
		tmp = stack;
	}
}

void	free_all(t_stack *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
}
