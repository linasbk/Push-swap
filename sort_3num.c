#include"push_swap.h"

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
