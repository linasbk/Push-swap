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

#include"push_swap.h"

int	compare_top_bottom(t_stack *stacks, int pos, int size)
{
	int	top;
	int	bottom;

	top = get_index(stacks->b, (pos - 1));
	bottom = size - top;
	if (top >= bottom)
		return (bottom);
	else
		return (top);
}

void	rotate_and_push(int index, int size, t_stack *stacks, int i)
{
	if (index < (size / 2))
	{
		while (i++ < index)
			rotate(stacks, 'b');
	}
	else
		while (i++ < size - index)
			reverse_rotate(stacks, 'b');
	ft_push_a(stacks);
}

void	sort_and_push(t_stack *stacks, int size, int i, int index)
{
	t_stack_list	*tmp;

	tmp = stacks->b;
	while (stacks->b)
	{
		i = 0;
		if (size == 1 || compare_top_bottom(stacks, size, size)
			<= compare_top_bottom(stacks, size - 1, size))
		{
			index = get_index(stacks->b, (size - 1));
			rotate_and_push(index, size, stacks, i);
			size--;
		}
		else
		{
			index = get_index(stacks->b, (size - 2));
			rotate_and_push(index, size, stacks, i);
			index = get_index(stacks->b, (size - 1));
			i = 0;
			size --;
			rotate_and_push(index, size, stacks, i);
			size --;
			swap_stack(stacks, 'a');
		}
	}
}

void	push_chunks(t_stack *stacks, int half, int chunk_size, int end_chunk)
{
	int	chunk_count;		

	chunk_count = 0;
	while (stacks->a != NULL)
	{
		while (chunk_count < chunk_size && stacks->a)
		{	
			if (stacks->a && (stacks->a->pos < chunk_size))
			{
				ft_push_b(stacks);
				chunk_count++;
				if (stacks->b->pos > (chunk_size - half))
				{
					if (stacks->a && stacks->a->pos >= chunk_size
						&& chunk_count != chunk_size)
						rotate(stacks, 's');
					else
						rotate(stacks, 'b');
				}
			}
			else
				rotate(stacks, 'a');
		}
		chunk_size += end_chunk;
	}
}

void	sort_num(t_stack *stacks, int size)
{
	int	chunk_size;
	int	end_chunk;		
	int	half;

	if (size > 5 && size <= 200)
	{
		chunk_size = size / 5;
		end_chunk = (stacks->size / 5);
	}
	if (size > 200)
	{
		chunk_size = size / 9;
		end_chunk = (stacks->size / 9);
	}
	half = chunk_size / 2;
	push_chunks(stacks, half, chunk_size, end_chunk);
	sort_and_push(stacks, size, 0, 0);
}
