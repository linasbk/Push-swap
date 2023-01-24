/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:10 by lsabik            #+#    #+#             */
/*   Updated: 2023/01/24 13:48:20 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

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

int	ft_isdigit(char **av)
{
	size_t		i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return 1;
		else
			i++;
	}
	return 0;
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
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

int	ft_parse(char **av)
{
	if (!(*av) || !(**av))
		return 1;
	return ft_isdigit(av) || ft_dup(av);
}
