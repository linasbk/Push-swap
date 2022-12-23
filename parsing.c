/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:10 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:53:12 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"include/push_swap.h"

int	ft_isdigit(char **av)
{
	size_t		i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_dup(char **av)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse(char **av)
{
	return (ft_isdigit(av) || ft_dup(av));
}

// void    assign_index(t_stack *stack_a, int stack_size)
// {
//     t_stack    *ptr;
//     t_stack    *highest;
//     int        value;

//     while (--stack_size > 0)
//     {
//         ptr = stack_a;
//         value = INT_MIN;
//         highest = NULL;
//         while (ptr)
//         {
//             if (ptr->value == INT_MIN && ptr->index == 0)
//                 ptr->index = 1;
//             if (ptr->value > value && ptr->index == 0)
//             {
//                 value = ptr->value;
//                 highest = ptr;
//                 ptr = stack_a;
//             }
//             else
//                 ptr = ptr->next;
//         }
//         if (highest != NULL)
//             highest->index = stack_size;
//     }
// }
