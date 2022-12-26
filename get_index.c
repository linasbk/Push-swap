#include"include/push_swap.h"

void	get_index(t_stack_list *a)
{
	t_stack_list	*current_pos;
	t_stack_list	*compare;
	int				pos;

	current_pos = a;
	while(current_pos)
	{
		pos = 0;
		compare = a;
		while(compare)
		{
			if (compare->content < current_pos->content)
				pos++;
			compare = compare->next;
		}
		current_pos->pos = pos;
		current_pos = current_pos->next;
	}
}
