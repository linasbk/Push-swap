#include"push_swap.h"

static int	ft_isspace(char str)
{
	if (str == '\t' || str == '\f' || str == '\v'
		|| str == '\n' || str == '\r' || str == ' ')
		return (1);
	return (0);
}

long	ft_atoi(char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + *str - 48;
		str++;
	}
	return (sign * num);
}

t_stack_list	*ft_lstnew(int content)
{
	t_stack_list	*node;

	node = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!node)
		return (NULL);
	node->content = content ;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack_list **lst, t_stack_list *new)
{
	t_stack_list	*last_node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

t_stack_list	*ft_lstlast(t_stack_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst ->next;
	return (lst);
}