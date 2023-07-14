/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:16:19 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 14:57:06 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_numeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
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
			ft_putstr_fd("Error\n", 2);
			exit(NOT_NUMERIC);
		}
	}
	if (!(ft_checker2(ac, av, 0)))
	{
		ft_putstr_fd("Error\n", 2);
		exit(INVALID_INT);
	}
	if (ft_check_if_sorted(ac, av, 0))
		exit (SORTED_ALREADY);
	return (1);
}

int	ft_checker2(int ac, char *av[], int i)
{
	int	j;
	int	save;

	save = i;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
	}
	i = save;
	while (++i < ac)
		if ((ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN))
			return (0);
	return (1);
}

int	ft_check_if_sorted(int ac, char *av[], int i)
{
	while (++i < ac - 1)
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (0);
	return (1);
}
