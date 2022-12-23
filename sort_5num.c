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
	int				old_max;
	t_stack_list	*tmp;


	// min = min_value(stacks->a);
	// pos = find_pos(stacks->a,pos);
	// size = stacks->a->size;
	// if (stacks->a->content != min)
	// {
	// 	if ()
	// }
	tmp = stacks->a;
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
        print_pb(stacks->a, stack_b);
		size--;
    }
    ft_sort_3nums(stacks->a);
    while (ft_stack_size(stack_b) != 0)
        print_pa(stack_b, stacks->a);








	while (size > 3 && !(check_sort(&stacks->a)))
	{
		ft_push_b(stacks);
		size--;
	}
	if (size == 3 && !(check_sort(&stacks->a)))
		sort_3num(stacks);
	old_max = max_value(stacks->a);
	if (check_sort(&stacks->a))
		ft_push_a(stacks);
	if (stacks->a->content == max_value(stacks->a) && stacks->a->content > old_max && !(check_sort(&stacks->a)))
		reverse_rotate(stacks, 'a');
	ft_push_a(stacks);
	if (!(check_sort(&stacks->a)))
		reverse_rotate(stacks, 'a');
}
void    ft_sort_5nums(t_stack stack_a, t_stack stack_b, int i)
{
    t_stack    stack_a_clone;
    int        min;

    i = 0;
    stack_a_clone =stack_a;
    while ((ft_stack_size(stack_a)) != 3)
    {
        min = ft_is_min(stack_a);
        while (stack_a_clone->data != min)
        {
            if (ft_find_position(stack_a, min) >= (ft_stack_size(stack_a) / 2))
                print_rra(stack_a);
            else
                print_ra(stack_a);
            stack_a_clone = *stack_a;
        }
        print_pb(stack_a, stack_b);
    }
    ft_sort_3nums(stack_a);
    while (ft_stack_size(stack_b) != 0)
        print_pa(stack_b, stack_a);
}
