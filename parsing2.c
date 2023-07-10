/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:47:50 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/10 14:58:59 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_valid2(char *in_quotes)
{
	int	i;
	char	**splitted;
	splitted = ft_recursive_split(in_quotes, NULL, 0, " \t");
	
	i = -1;
	while (splitted[++i])
	{
		if (!(ft_numeric(splitted[i])
			&& (ft_atoi(splitted[i]) > INT_MIN
				&& ft_atoi(splitted[i]) < INT_MAX) && *splitted[i]))
		return (0);
	}
	printf ("HERE %d\n", i);
	if (ft_check_if_sorted(i, splitted))
		exit (SORTED_ALREADY);
	ft_create_stack(i + 1, splitted);
	i = -1;
	while (splitted[++i])
		free (splitted[i]);
	free (splitted);	
	return (1);
}

