#include"push_swap.h"

void	ft_lstadd_front(t_stack_list **lst, t_stack_list *new)
{
	if (new && lst)
	{
		new ->next = *lst;
		*lst = new;
	}
}
