/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:48:20 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/18 23:42:15 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_store *store)
{
	if (store->count == 2)
		sa_sb(store->stack_a, STACK_A);
	// else
	// {
	// 	ft_min_max_search(store);
	// }	
}

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
	}
	else
	{
		if (stack_a->value < store->min_odd)
			store->min_odd = stack_a->value;
		if (stack_a->value > store->max_odd)
			store->max_odd = stack_a->value;	
	}
	stack_a->index = i;
	ft_min_max_search(store, stack_a->next, i + 1);		
}


// void	ft_min_max_search(t_store *store)
// {
// 	t_stack	*current;
// 	int		i;

// 	current = store->stack_a;
// 	store->min_even = INT_MAX; 
// 	store->min_odd = INT_MAX; 
// 	store->max_even = INT_MIN;
// 	i = 0;
// 	while (current)
// 	{
// 		if (current->value % 2 == 0)
// 		{
// 			if (current->value < store->min_even)
// 				store->min_even = current->value;
// 			if (current->value > store->max_even)
// 				store->max_even = current->value;	
// 		}
// 		else
// 			if (current->value < store->min_odd)
// 				store->min_odd = current->value;
// 		current->index = i++;
// 		current = current->next;
// 	}
// }
