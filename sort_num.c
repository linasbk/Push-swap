/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:45 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:53:47 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"include/push_swap.h"

void	sort_num(t_stack *stacks)
{
	int				size;
	int             chunk_size;
	int             chunk_count;

	chunk_count = 0;
	size = stacks->a->size;
	chunk_size = size / 5;

	while (stacks->a != NULL)
	{
		while(chunk_count < chunk_size && stacks->a)
		{
			if(stacks->a && (stacks->a->pos < chunk_size))
			{
				ft_push_b(stacks);
				chunk_count++;
			}
			else
				rotate(stacks, 'a');
		}
		chunk_size += size / 5;
	}
}
