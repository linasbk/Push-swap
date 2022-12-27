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
}

int	main(int ac, char **av)
{
	t_stack	*stacks;
	char	*arg;
	int		size;
	char	**args;

	if (ac < 2)
		exit(EXIT_FAILURE);
	stacks = ft_init();
	arg = join_args(av, ac);
	args = ft_split(arg, ' ');
	fill_stack(stacks, args);
	get_pos(stacks->a);
	size = stacks->a->size;
	// if (stacks->a->size <= 3)
	// 	sort_3num(stacks);
	// if (stacks->a->size > 3 && stacks->a->size <= 5)
	// 	sort_5num(stacks);
	if (size > 5)
		sort_num(stacks, size);
	// printf("\n****** A ******\n\n");
	// while(stacks->a)
	// {
	// 	if (stacks->a)
	// 		printf("%d,%d\n", stacks->a->content,stacks->a->pos);
	// 	stacks->a = stacks->a->next;
	// }
	// 	printf("\n****** B ******\n\n");
	// while(stacks->b)
	// {
	// 	printf("%d\n", stacks->b->content);
	// 	stacks->b = stacks->b->next;
	// }
	free_all(stacks);
	// system("leaks push_swap");
	return (0);
}
