/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:08:29 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/05 20:23:54 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_marker(t_store *store, t_stack *stack_a, int copy[], int chunk_index)
{
	int	pos;
	int	range_start;
	int	range_end;

	pos = ft_find_pos_array(copy, store->count_a, stack_a->value, 0);
	range_start = (chunk_index - 1) * store->percent10;
	range_end = chunk_index * store->percent10;
	if (pos >= range_start && pos < range_end)
		stack_a->flag = chunk_index;
	if (stack_a->next)
		ft_marker(store, stack_a->next, copy, chunk_index);
	else if (chunk_index < 10)
		ft_marker(store, store->stack_a, copy, chunk_index + 1);
}

void	ft_rotate_stack(t_store *store, int cost, int dir, int stack_flag)
{
	while (--cost)
	{
		if (stack_flag == STACK_A)
		{
			if (dir == UP)
				ra(store, STACK_A);
			else if (dir == DOWN)
				rra(store, STACK_A);
		}
		else if (stack_flag == STACK_B)
		{
			if (dir == UP)
				rb(store, STACK_B);
			else if (dir == DOWN)
				rrb(store, STACK_B);
		}
	}
}

int	ft_closer(t_store *store, int flag, int *dir)
{
	int	start_cost;
	int	end_cost;
	int	dir_save;

	start_cost = ft_find_the_cost(ft_from_start(store->stack_a, flag),
			store->count_a, dir);
	dir_save = *dir;
	end_cost = ft_find_the_cost(ft_from_end(store->tail_a, flag),
			store->count_a, dir);
	if (start_cost <= end_cost)
	{
		*dir = dir_save;
		return (start_cost);
	}
	else
	{
		return (end_cost);
	}
}

int	ft_find_the_cost(int index, int count, int *dir)
{
	if (index <= count - index)
	{
		*dir = UP;
		return (index + 1);
	}
	else
	{
		*dir = DOWN;
		return (count - index + 1);
	}
}

int	ft_count_flags(t_stack *stack_a, int find_flag)
{
	if (!stack_a)
		return (0);
	if (stack_a->flag == find_flag)
		return (1 + ft_count_flags(stack_a->next, find_flag));
	else
		return (ft_count_flags(stack_a->next, find_flag));
}
