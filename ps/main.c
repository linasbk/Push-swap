/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:00 by lsabik            #+#    #+#             */
/*   Updated: 2023/01/24 13:44:41 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_stack	*ft_init(void)
{
	t_stack	*stacks;

	stacks = (t_stack *)malloc(sizeof(t_stack));
	stacks->a = NULL;
	stacks->b = NULL;
	return stacks);
}

void	fill_stack(t_stack *stacks, char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		ft_lstadd_back(&stacks->a, ft_lstnew(ft_atoi(args[i]), stacks));
		i++;
	}
	if (ft_parse(args))
		ft_error();
}

void	is_empty(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (ft_isspace(av[i][j]))
			j++;
		if (av[i][j] == 0)
			ft_error();
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stacks;
	char	*arg;
	char	**args;
	int		i;

	i = 0;
	if (ac < 2)
		exit(EXIT_FAILURE);
	is_empty(ac, av);
	stacks = ft_init();
	arg = join_args(av, ac);
	args = ft_split(stacks, arg, ' ');
	fill_stack(stacks, args);
	get_pos(stacks->a);
	if (stacks->a->size <= 3)
		sort_3num(stacks);
	if (stacks->a->size > 3 && stacks->a->size <= 5)
		sort_5num(stacks);
	if (stacks->a->size > 5)
		sort_num(stacks, stacks->a->size);
	free_all(stacks);
	return 0);
}
