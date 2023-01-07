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

int	get_index(t_stack_list *b, int num)
{
	t_stack_list	*tmp;
	int				i;

	tmp = b;
	i = 0;
	while (tmp)
	{
		if (tmp->pos == num)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void sort_and_push(t_stack *stacks, int size)
{
	t_stack_list	*tmp;
	int				i;
	int				index;

	tmp = stacks->b;
	while(stacks->b)
	{
		i = 0;
		index = get_index(stacks->b,(size - 1));
		if (index <= (size / 2))
		{
			while (i++ < index)
				rotate(stacks, 'b');
		}
		else
			while (i++ < size - index)
				reverse_rotate(stacks, 'b');
		ft_push_a(stacks);
		size--;
	}
}

void	push_chunks(t_stack *stacks, int size,  int chunk_size, int chunk_count)
{
	int				half;

	half = chunk_size / 2;
	while (stacks->a != NULL)
	{
		while(chunk_count < chunk_size && stacks->a)
		{	
			if(stacks->a && (stacks->a->pos < chunk_size))
			{
				ft_push_b(stacks);
				if (stacks->b->pos  >= (chunk_size - half))
				{
					if (stacks->a && !(stacks->a->pos < chunk_size))
						rotate(stacks, 's');
					else
					rotate(stacks, 'b');
				}
				chunk_count++;
			}
			else
				rotate(stacks, 'a');
		}
		chunk_size += size / 5;
	}
}

void	sort_num(t_stack *stacks, int size)
{
	int             chunk_size;
	int             chunk_count;		
	

	chunk_count = 0;
	if (size > 5 && size <= 200)
		chunk_size = size / 5;
	if (size > 200)
		chunk_size = size / 6;
	push_chunks(stacks, size, chunk_size, chunk_count);
	sort_and_push(stacks, size);
}
