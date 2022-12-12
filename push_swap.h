#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"stdlib.h"
# include<unistd.h>
# include<limits.h>
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}              t_s   tack_list;

typedef struct s_stack
{
	t_stack_list *A;
	t_stack_list *B;
}              t_stack;

void			ft_error();
int				ft_atoi(char *str);
int				ft_parse(char **av);
void			ft_lstadd_back(t_stack_list **lst, t_stack_list *new);
void			swap_stack(t_stack *stacks, char var);
t_stack_list	*ft_lstnew(int content);
t_stack_list	*ft_lstlast(t_stack_list *lst);

#endif