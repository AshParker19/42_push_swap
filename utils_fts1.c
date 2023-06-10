/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:16:19 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/09 22:50:48 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_checker(int ac, char *av[])
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_numeric(av[i]))
		{
			ft_putstr("Error\n");
			exit(NOT_NUMERIC);
		}
	}	
	if (!(ft_checker2(ac, av)))
	{
		{
			ft_putstr("Error\n");
			exit(INVALID_INT);
		}
	}
	return (1);
}
