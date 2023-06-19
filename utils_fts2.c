/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:47:11 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/19 18:01:37 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_limits(t_store *store)
{
	store->min_even = INT_MAX; 
	store->max_even = INT_MIN;
	store->min_odd = INT_MAX; 
	store->max_odd = INT_MIN;
	store->even_count = 0;
	store->odd_count = 0;
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

int	ft_get_direction(t_store *store, int value, int *dir)
{
	return(ft_find_the_cost(ft_find_position(store->stack_a, value), store->count, dir));
}

int	ft_find_the_cost(int index, int count, int *dir)
{
	if (index <= count - index)
	{
		*dir = 1;
		return (index + 1);
	}
	else
	{
		*dir = 2;
		return (count - index + 1);
	}
}

// int	ft_find_the_cost(int index, int count)
// {
// 	if (index <= count - index)
// 		return (index + 1);
// 	else
// 		return (count - index + 1);
// }

// int	ft_get_direction(t_store *store, int min_value, int max_value)
// {
// 	int	lower_cost;
// 	int	higher_cost;
	
// 	lower_cost = ft_find_the_cost(ft_find_position(store->stack_a, min_value), store->count);
// 	higher_cost = ft_find_the_cost(ft_find_position(store->stack_a, max_value), store->count);
// 	if (lower_cost <= higher_cost)
// 		return (lower_cost);
// 	else
// 		return (higher_cost);
// }


void	ft_min_max_search(t_store *store, t_stack *stack_a, int i)
{
	if (!stack_a)
		return ;
	if (stack_a->value % 2 == 0)
	{
		if (stack_a->value < store->min_even)
			store->min_even = stack_a->value;
		if (stack_a->value > store->max_even)
			store->max_even = stack_a->value;
		store->even_count += 1;	
	}
	else
	{
		if (stack_a->value < store->min_odd)
			store->min_odd = stack_a->value;
		if (stack_a->value > store->max_odd)
			store->max_odd = stack_a->value;	
		store->odd_count += 1;	
	}
	stack_a->index = i;
	ft_min_max_search(store, stack_a->next, i + 1);		
}
