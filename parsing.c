/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:16:19 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/08 22:57:19 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid(int ac, char *av[])
{
	if (ac == 1 || (ac == 2 && ft_numeric(av[1])
			&& (ft_atoi(av[1]) > INT_MIN
				&& ft_atoi(av[1]) < INT_MAX) && *av[1]))
		return (1);
	return (0);
}

int	ft_numeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_checker(int ac, char *av[])
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_numeric(av[i]) || !*av[i])
		{
			ft_putstr("Error\n");
			exit(NOT_NUMERIC);
		}
	}	
	if (!(ft_checker2(ac, av)))
	{
		ft_putstr("Error\n");
		exit(INVALID_INT);
	}
	if (ft_check_if_sorted(ac, av))
		exit (SORTED_ALREADY);
	return (1);
}

int	ft_checker2(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
		}	
	}
	i = -1;
	while (++i < ac)
		if ((ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN))
			return (0);
	return (1);
}

int	ft_check_if_sorted(int ac, char *av[])
{
	int	i;
	
	i = 0;
	while (++i < ac - 1)
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (0);
	return (1);
}

// it doesnt sort 9 numbers