/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:52:23 by lsabik            #+#    #+#             */
/*   Updated: 2023/01/24 13:46:53 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_sort(t_stack_list **stack)
{
	t_stack_list	*tmp;

	tmp = *stack;
	while (*stack && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return 0;
		tmp = tmp->next;
	}
	return 1;
}
