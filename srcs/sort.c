/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:48:20 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 14:58:01 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_main(t_store *store, int copy[])
{
	if (store->count_a == 2)
		sa_sb(store->stack_a, STACK_A);
	else if (store->count_a == 3)
		ft_sort_3(store);
	else if (store->count_a == 4
		|| store->count_a == 5)
		ft_sort_4_5(store, store->count_a);
	else if (store->count_a < 10)
		ft_sort_less10(store, 0);
	else
		ft_almighty_ps(store, copy);
}

void	ft_sort_3(t_store *store)
{
	if (store->stack_a->value > store->stack_a->next->value
		&& store->stack_a->value > store->stack_a->next->next->value)
		ra(store, STACK_A);
	if (store->stack_a->next->value > store->stack_a->value
		&& store->stack_a->next->value > store->stack_a->next->next->value)
		rra(store, STACK_A);
	if (store->stack_a->value > store->stack_a->next->value)
		sa_sb(store->stack_a, STACK_A);
}

void	ft_sort_4_5(t_store *store, int save)
{
	int	smallest_index;
	int	i;

	i = 2;
	while (i)
	{
		store->smallest = INT_MAX;
		ft_find_the_smallest(store, store->stack_a, 0);
		smallest_index = ft_find_position(store->stack_a, store->smallest);
		if (smallest_index <= i)
			while (store->stack_a->value != store->smallest)
				ra(store, STACK_A);
		else
			while (store->stack_a->value != store->smallest)
				rra(store, STACK_A);
		pb(store);
		if (save == 4)
			break ;
		i--;
	}
	ft_sort_3(store);
	pa(store);
	if (save == 5)
		pa(store);
}

void	ft_sort_less10(t_store *store, int flag)
{
	int	smallest_index;
	int	i;
	int	j;

	if (flag == 1)
		i = store->count_a - 5;
	else
		i = store->count_a;
	j = i;
	while (i)
	{
		store->smallest = INT_MAX;
		ft_find_the_smallest(store, store->stack_a, 0);
		smallest_index = ft_find_position(store->stack_a, store->smallest);
		ft_rotate_up(store, smallest_index, i);
		pb(store);
		i--;
	}
	if (flag == 1)
		ft_sort_4_5(store, 5);
	while (j--)
		pa(store);
}
