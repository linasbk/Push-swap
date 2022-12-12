#include"push_swap.h"
#include<stdio.h>

void	ft_error()
{
	write(1, "\033[1;31m Error\n", 15);
	exit(EXIT_FAILURE);
}

t_stack    *ft_init(int ac)
{
    t_stack *stacks;

    stacks = (t_stack *)malloc(sizeof(t_stack) * 1);
    stacks->A = (t_stack_list*)malloc((ac - 1) * sizeof(t_stack_list));
    if (!stacks->A)
		exit(EXIT_FAILURE);
	stacks->B = (t_stack_list*)malloc((ac - 1) * sizeof(t_stack_list));
	if (!stacks->B)
		exit(EXIT_FAILURE);
	stacks->A = NULL;
	stacks->B = NULL;
    return(stacks);
}

int main (int ac, char **av)
{
    t_stack *stacks;
	int		i;
	char	var = 'a';

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (ft_parse(av))
		ft_error();
    stacks = ft_init(ac);
	i = 0;
	while (av[++i])
		ft_lstadd_back(&stacks->A, ft_lstnew(ft_atoi(av[i])));
	swap_stack(stacks, var);
	printf("\n****** A ******\n\n");
	while(stacks->A)
	{
		printf("%d\n", stacks->A->content);
		stacks->A = stacks->A->next;
	}
	// printf("\n\n\nb\n\n\n");
	// while(stacks->B)
	// {
	// 	printf("%d\n", stacks->B->content);
	// 	stacks->B = stacks->B->next;
	// }
	return 0;
}