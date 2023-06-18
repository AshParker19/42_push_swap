/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:47:11 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/18 22:03:14 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_limits(t_store *store)
{
	store->min_even = INT_MAX; 
	store->max_even = INT_MIN;
	store->min_odd = INT_MAX; 
	store->max_odd = INT_MIN;
}

int	ft_find_position(t_stack *stack_a, int to_find)
{
	if (!stack_a)
		return (-1);
	if (stack_a->value == to_find)
		return (stack_a->index);
	else
		return (ft_find_position(stack_a->next, to_find));
}

int	ft_get_direction(t_store *store, int min_value, int max_value)
{
	int	small_cost;
	int	big_cost;
	
	small_cost = ft_find_the_cost(ft_find_position(store->stack_a, min_value), store->count);
	big_cost = ft_find_the_cost(ft_find_position(store->stack_a, max_value), store->count);
	if (small_cost <= big_cost)
		return (small_cost);
	else
		return (big_cost);
}

int	ft_find_the_cost(int index, int count)
{
	if (index <= count - index)
		return (index + 1);
	else
		return (count - index + 1);
}
