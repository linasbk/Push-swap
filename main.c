/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:00 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:53:02 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"include/push_swap.h"

void	ft_error(void)
{
	write(1, "\033[1;31m Error\n", 15);
	exit(EXIT_FAILURE);
}

t_stack	*ft_init(void)
{
	t_stack	*stacks;

	stacks = (t_stack *)malloc(sizeof(t_stack));
	stacks->a = NULL;
	stacks->b = NULL;
	return (stacks);
}

void	get_pos(char **arg, t_stack_list *a)
{
	int	i;
	size_t	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] < arg[i + 1])
		{
			a->pos = j;
			j++;
			i++;
		}
		else
			i++;
	}
}

void	fill_stack(t_stack *stacks, char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		ft_lstadd_back(&stacks->a, ft_lstnew(ft_atoi(args[i])));
		i++;
	}
	stacks->a->size = i;
	if (ft_parse(args))
		ft_error();
	get_pos(args, stacks->a);
}

int	main(int ac, char **av)
{
	t_stack	*stacks;
	char	*arg;
	char	**args;

	if (ac < 2)
		exit(EXIT_FAILURE);
	stacks = ft_init();
	arg = join_args(av, ac);
	args = ft_split(arg, ' ');
	fill_stack(stacks, args);
	if (stacks->a->size <= 3)
		sort_3num(stacks);
	// if (stacks->a->size > 3 && stacks->a->size <= 5)
	// 	sort_5num(stacks);
	// if (stacks->a->size > 5)
	// 	sort_num(stacks);
	get_index(stacks->a);
	printf("\n****** A ******\n\n");
	while(stacks->a)
	{
		printf("%d,%d\n", stacks->a->content,stacks->a->pos);
		stacks->a = stacks->a->next;
	}
	free_all(stacks);
	// system("leaks push_swap");
	return (0);
}
