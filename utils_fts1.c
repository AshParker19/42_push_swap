/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:47:11 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/03 21:22:35 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copy_values(t_stack *stack_a, int copy[], int i)
{
	if (!stack_a)
		return ;
	copy[i] = stack_a->value;
	ft_copy_values(stack_a->next, copy, i + 1);
}

void	ft_sort_copy(int copy[], int size)
{
	int	i;
	int	j;
	int	swap;

	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (copy[i] > copy[j])
			{
				swap = copy[i];
				copy[i] = copy[j];
				copy[j] = swap;
			}
			j++;
		}
	}
}

int	ft_find_pos_array(int copy[], int size, int to_find, int i)
{
	if (i < size)
	{
		if (copy[i] == to_find)
			return (i);
		else
			return (ft_find_pos_array(copy, size, to_find, i + 1));
	}
	return (-1);
}

void	ft_index(t_stack *stack_a, int i)
{
	if (!stack_a)
		return ;
	stack_a->index = i;
	ft_index(stack_a->next, i + 1);
}

char	*ft_ternary(int condition, char *expression1, char *expression2)
{
	if (condition)
		return (expression1);
	else
		return (expression2);
}
