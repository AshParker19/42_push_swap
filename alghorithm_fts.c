/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghorithm_fts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:01:04 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/19 16:55:01 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_store *store)
{
	int	dir;
	int	cost;
	
	ft_min_max_search(store, store->stack_a, 0);
	while (store->even_count)
	{
		cost = ft_get_direction(store, store->min_even, &dir);
		if (dir == 1)
			ft_rotate_stack_a(store, cost, UP, NEUTRAL);
		else
			ft_rotate_stack_a(store, cost, DOWN, NEUTRAL);
		ft_reset_limits(store);
		ft_min_max_search(store, store->stack_a, 0);
	}
	while (store->odd_count)
	{
		cost = ft_get_direction(store, store->min_odd, &dir);
		if (dir == 1)
			ft_rotate_stack_a(store, cost, UP, STACK_B);
		else
			ft_rotate_stack_a(store, cost, DOWN, STACK_B);
		ft_reset_limits(store);
		ft_min_max_search(store, store->stack_a, 0);
	}
	ft_print_list(store);
}

void	ft_rotate_stack_a(t_store *store, int cost, int dir_flag, int stack_flag)
{
	while (--cost)
	{
		if (dir_flag == UP)
			ra_rb(store->stack_a, STACK_A);
		else
			rra_rrb(store->stack_a, STACK_A);
	}
	pa_pb(store, &store->stack_a, &store->stack_b, STACK_A);
	if (stack_flag == STACK_B)
		ra_rb(store->stack_b , STACK_B);
}
