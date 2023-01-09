/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:54:58 by lsabik            #+#    #+#             */
/*   Updated: 2022/12/22 16:55:00 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"stdlib.h"
# include<unistd.h>
# include<limits.h>

typedef struct s_list
{
	int				size;
	int				pos;
	int				content;
	struct s_list	*next;
}				t_stack_list;

typedef struct s_stack
{
	t_stack_list	*a;
	t_stack_list	*b;
	int				size;
}				t_stack;

void			ft_error(void);
long			ft_atoi(char *str);
int				ft_parse(char **av);
void			ft_lstadd_back(t_stack_list **lst, t_stack_list *new);
void			ft_lstadd_front(t_stack_list **lst, t_stack_list *new);
void			swap_stack(t_stack *stacks, char var);
void			ft_push_b(t_stack *stacks);
void			ft_push_a(t_stack *stacks);
void			rotate(t_stack *stacks, char var);
void			reverse_rotate(t_stack *stacks, char var);
void			free_all(t_stack *stacks);
char			*join_args(char **av, int ac);
int				check_sort(t_stack_list **stack);
char			**ft_split(t_stack *stacks, char const *s, char c);
t_stack_list	*ft_lstnew(int content, t_stack *stacks);
t_stack_list	*ft_lstlast(t_stack_list *lst);
int				get_num_word(char *s, char sep);
char			*get_next_line(int fd);
int				ft_parse(char **av);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s1);
char			**ft_split(t_stack *stacks, char const *s, char c);
char			*ft_substr(char *s, unsigned int start, size_t len);
size_t			ft_strlen(char *s);
void			ft_error(void);
int				ft_isspace(char str);
int				check_sort(t_stack_list **stack);
int				ft_strcmp(char *s1, char *s2);
#endif
