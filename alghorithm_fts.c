/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghorithm_fts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:01:04 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/19 20:15:49 by anshovah         ###   ########.fr       */
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
	// if (store->tail_b)
	// 	printf("TAIL_B VALUE: %d\n", store->tail_b->value);
	while (store->stack_b)
	{
		if (store->stack_b->value > store->tail_b->value)
			pa_pb(store, &store->stack_b, &store->stack_a, STACK_B);
		else
		{
			rra_rrb(store, store->stack_b, STACK_B);
			pa_pb(store, &store->stack_b, &store->stack_a, STACK_B);
		}	
	}
	// ft_print_list(store);
	// if (ft_check_if_sorted(store->stack_a))
	// 	printf (GREEN"========== OK! ==========\n"RESET);
	// else
	// 	printf(RED"========== NO ==========\n"RESET);	
}

void	ft_rotate_stack_a(t_store *store, int cost, int dir_flag, int stack_flag)
{
	while (--cost)
	{
		if (dir_flag == UP)
			ra_rb(store, store->stack_a, STACK_A);
		else
			rra_rrb(store, store->stack_a, STACK_A);
	}
	pa_pb(store, &store->stack_a, &store->stack_b, STACK_A);
	if (stack_flag == STACK_B)
		ra_rb(store, store->stack_b , STACK_B);
}
