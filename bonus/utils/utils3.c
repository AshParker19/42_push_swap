/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:35:34 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/15 12:58:08 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	c1 = s1[i];
	c2 = s2[i];
	return (c1 - c2);
}

int	ft_checker_b(int ac, char *av[])
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
	return (1);
}

void	ft_free_everything(t_store *store, char **ops_store)
{
	int	i;

	i = -1;
	while (ops_store[++i])
		free (ops_store[i]);
	free (ops_store);
	store->stack_a = ft_free_stack(store->stack_a);
	store->stack_b = ft_free_stack(store->stack_b);
}
