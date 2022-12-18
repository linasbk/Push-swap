#include"push_swap.h"
#include<stdio.h>

void	ft_error()
{
	write(1, "\033[1;31m Error\n", 15);
	exit(EXIT_FAILURE);
}

t_stack    *ft_init()
{
    t_stack *stacks;

    stacks = (t_stack *)malloc(sizeof(t_stack) * 1);
	stacks->A = NULL;
	stacks->B = NULL;
    return(stacks);
}
void sort_3num(t_stack	*stacks)
{
	t_stack_list	*tmp;

	tmp = stacks->A;
	if (tmp->next->content > tmp->next->next->content && tmp->content < tmp->next->next->content)
		{
			swap_stack(stacks, 'a');
			rotate(stacks,'a');
		}
}
int main (int ac, char **av)
{
    t_stack *stacks;
	int		i;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (ft_parse(av))
		ft_error();
    stacks = ft_init();
	i = 0;
	while (av[++i])
		ft_lstadd_back(&stacks->A, ft_lstnew(ft_atoi(av[i])));
	// swap_stack(stacks, 'a');
	// ft_push_b(stacks);
	// reverse_rotate(stacks, 'a');
	if (ac == 4)
		sort_3num(stacks);
	printf("\n****** A ******\n\n");
	while(stacks->A)
	{
		printf("%d\n", stacks->A->content);
		stacks->A = stacks->A->next;
	}
	// free_all(stacks);
	// printf("\n****** B ******\n\n");
	// while(stacks->B)
	// {
	// 	printf("%d\n", stacks->B->content);
	// 	stacks->B = stacks->B->next;
	// }

	// if(check_sort(&stacks->A)) //not sorted
	// 	printf("not sorted %d", check_sort(&stacks->A));
	free_all(stacks);
	// system("leaks push_swap");
	return 0;
}

