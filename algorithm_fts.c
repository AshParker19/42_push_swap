/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:45:29 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/13 15:29:29 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_store *store, int copy[])
{
	ft_copy_values(store->stack_a, copy, 0);
	ft_sort_copy(copy, store->count_a);
	ft_index(store->stack_a, 0);
	ft_marker(store, store->stack_a, copy, 1);
	ft_push_b_main(store);

	if (store->chunk_num == 8)
		ft_sort_4_5(store, 4);
	if (store->chunk_num == 14)	
		ft_sort_less10(store);
	ft_push_to_a(store, 0, 1, 0);

	// ft_print_list(store);
}

// REM 6
// 17 chunks 29 nums == 5240
// 13 c 38 n == 5225, too much blue
// 19 c 26 n == 5310

// REM 5
// 15 c 33 n == 5223
// 33 c 15 n == too much

// REM 20
// 24 c 20 n == 5662, too much blue
// 20 c 24 n == 5406
// 16 c 30 n == 5226
// 15 c 32 n == 5222

// REM 10
// 14 c 35 n == 5183 BEST!!!
// 35 c 14 n == too much
// 10 c 49 n == 5416
