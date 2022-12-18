#include"push_swap.h"

void sort_3num(t_stack	*stacks)
{
	t_stack_list	*tmp;

	tmp = stacks->A;
    if (check_sort(stacks->A))
        return ;
	if (tmp->content > tmp->next->content)
		{
			swap_stack(stacks, 'a');
		}
    if ()
			rotate(stacks,'a');
}
//tmp->next->content > tmp->next->next->content && tmp->content < tmp->next->next->content