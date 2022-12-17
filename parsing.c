#include"push_swap.h"


int	ft_isdigit(char **av)
{
	size_t		i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '0')
			i++;
		else if (!ft_atoi(av[i]) || ft_atoi(av[i]) > INT_MAX || 
					ft_atoi(av[i]) < INT_MIN)
		    return (1);
		else
			i++;
	}
	return (0);
}

int	ft_dup(char **av)
{
	size_t		i;
	size_t		j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_parse(char **av)
{
    if (ft_isdigit(av)|| ft_dup(av))
		return (1);
	return (0);
}
