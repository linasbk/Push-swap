/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:50:16 by lsabik            #+#    #+#             */
/*   Updated: 2023/01/24 13:44:41 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	get_index(t_stack_list *b, int num)
{
	t_stack_list	*tmp;
	int				i;

	tmp = b;
	i = 0;
	while (tmp)
	{
		if (tmp->pos == num)
			return i);
		i++;
		tmp = tmp->next;
	}
	return -1);
}

void	get_pos(t_stack_list *a)
{
	t_stack_list	*current_pos;
	t_stack_list	*compare;
	int				pos;

	current_pos = a;
	while (current_pos)
	{
		pos = 0;
		compare = a;
		while (compare)
		{
			if (compare->content < current_pos->content)
				pos++;
			compare = compare->next;
		}
		current_pos->pos = pos;
		current_pos = current_pos->next;
	}
}
