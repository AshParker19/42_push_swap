/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:42:43 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/13 23:15:50 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_start_from_quotes(char *in_quotes)
{
	int		count;
	char	**splitted;

	count = 0;
	if (!ft_check_if_empty(in_quotes))
	{
		ft_putstr_fd("Error\n", 2);
		exit(NOT_NUMERIC);
	}
	splitted = ft_split(in_quotes, NULL, 0, ' ');
	while (splitted[count])
		count++;
	if (ft_check_splitted(splitted, count))
		ft_create_stack(count + 1, splitted, -1, 1);
	ft_free_splitted(splitted);
}

int	ft_check_if_empty(char *in_quotes)
{
	int	i;

	i = -1;
	if (!*in_quotes)
		return (0);
	while (in_quotes[++i])
	{
		if (in_quotes[i] != ' ')
			break ;
		if (!in_quotes[i + 1])
			return (0);
	}
	return (1);
}

int	ft_check_splitted(char **splitted, int count)
{
	int	i;

	i = -1;
	while (splitted[++i])
	{
		if (!ft_numeric(splitted[i]))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_splitted(splitted);
			exit(NOT_NUMERIC);
		}
	}
	if (!ft_checker2(count, splitted, -1))
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_splitted(splitted);
		exit(INVALID_INT);
	}
	if (ft_check_if_sorted(count, splitted, -1))
	{
		ft_free_splitted(splitted);
		exit (SORTED_ALREADY);
	}
	return (1);
}

void	ft_free_splitted(char *splitted[])
{
	int	i;

	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted);
}
