#include"push_swap.h"
#include<stdio.h>
void    ft_free(t_stack_list **stack_a)
{
    t_stack_list    *stack_a_clone;

    stack_a_clone = *stack_a;
    while (*stack_a && (*stack_a)->next)
    {
        stack_a_clone = (*stack_a)->next;
        free(*(stack_a));
        *stack_a = stack_a_clone;
    }
}
void	ft_error()
{
	write(1, "\033[1;31m Error\n", 15);
	exit(EXIT_FAILURE);
}

void free_all(t_stack *stacks)
{
	t_stack_list *tmp;
	t_stack_list *tmp1;

	tmp = stacks->A;
	while (stacks->A)
	{
		stacks->A = stacks->A->next;
		free(tmp);
		tmp = stacks->A;
	}
	tmp1 = stacks->B;
	while (stacks->B)
	{
		stacks->B = stacks->B->next;
		free(tmp1);
		tmp1 = stacks->B;
	}
	free(stacks);
}

t_stack    *ft_init()
{
    t_stack *stacks;

    stacks = (t_stack *)malloc(sizeof(t_stack) * 1);
	stacks->A = NULL;
	stacks->B = NULL;
    return(stacks);
}

int main (int ac, char **av)
{
    t_stack *stacks;
	int		i;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (ft_parse(av))
		ft_error();
    stacks = ft_init(o);
	i = 0;
	while (av[++i])
		ft_lstadd_back(&stacks->A, ft_lstnew(ft_atoi(av[i])));
	// swap_stack(stacks, 'a');
	ft_push_b(stacks);
	// reverse_rotate(stacks, 'a');
	// printf("\n****** A ******\n\n");
	// while(stacks->A)
	// {
	// 	printf("%d\n", stacks->A->content);
	// 	stacks->A = stacks->A->next;
	// }
	// free_all(stacks);
	// printf("\n****** B ******\n\n");
	// while(stacks->B)
	// {
	// 	printf("%d\n", stacks->B->content);
	// 	stacks->B = stacks->B->next;
	// }
	check_sort(stacks->A                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             );
	free_all(stacks);
	system("leaks push_swap");
	return 0;
}