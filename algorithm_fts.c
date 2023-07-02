/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:45:29 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/02 23:17:25 by anshovah         ###   ########.fr       */
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

void	ft_algorithm(t_store *store, int copy[])
{
	ft_index(store->stack_a, 0);
	ft_copy_values(store->stack_a, copy, 0);
	ft_sort_copy(copy, store->count_a);
	ft_marker(store, store->stack_a, copy, 1);
	ft_print_list(store);
}

// I need to find all the numbers of the current chunk index before increasing it