/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:44:16 by lsabik            #+#    #+#             */
/*   Updated: 2023/01/24 13:49:16 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*ft_init(void)
{
	t_stack	*stacks;

	stacks = (t_stack *)malloc(sizeof(t_stack));
	stacks->a = NULL;
	stacks->b = NULL;
	return  stacks;
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

void	compare_instructions(t_stack *stacks, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap_stack(stacks, 'a');
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_stack(stacks, 'b');
	else if (ft_strcmp(str, "ss\n") == 0)
		swap_stack(stacks, 's');
	else if (ft_strcmp(str, "pa\n") == 0)
		ft_push_a(stacks);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_push_b(stacks);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate(stacks, 'a');
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(stacks, 'b');
	else if (ft_strcmp(str, "rr\n") == 0)
		rotate(stacks, 's');
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(stacks, 'a');
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(stacks, 'b');
	else if (ft_strcmp(str, "rrr\n") == 0)
		reverse_rotate(stacks, 's');
	else
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
	char	*str;

	if (ac < 2)
		exit(EXIT_FAILURE);
	is_empty(ac, av);
	stacks = ft_init();
	arg = join_args(av, ac);
	args = ft_split(stacks, arg, ' ');
	fill_stack(stacks, args);
	str = get_next_line(0);
	if (check_sort(&stacks->a))
		return;
	while (str)
	{
		compare_instructions(stacks, str);
		free(str);
		str = get_next_line(0);
	}
	if (check_sort(&stacks->a) && stacks->b == NULL)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
}
