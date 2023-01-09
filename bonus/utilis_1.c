/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:54:27 by lsabik            #+#    #+#             */
/*   Updated: 2023/01/08 14:45:32 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

void	ft_lstadd_front(t_stack_list **lst, t_stack_list *new)
{
	if (new && lst)
	{
		new ->next = *lst;
		*lst = new;
	}
}

char	*ft_strdup(char *s1)
{
	char	*str;
	char	*res;

	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(str))
		return (0);
	res = str;
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	*str = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1);
	res = malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		res[len++] = s2[i++];
	return (res[len] = '\0', free (s1), res);
}

char	*join_args(char **av, int ac)
{
	char	*argument;
	int		index;

	argument = NULL;
	index = 1;
	while (index < ac)
	{
		argument = ft_strjoin(argument, av[index++]);
		argument = ft_strjoin(argument, " ");
	}
	return (argument);
}
