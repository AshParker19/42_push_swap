/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:54:51 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/12 13:39:09 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_manage_rra(t_store *store, int cost, int dir, int bottom_flag)
{
	if (store->stack_b && (store->stack_b->flag == bottom_flag
			|| store->stack_b->flag == bottom_flag - 2))
		rb(store, STACK_B);
	ft_rotate_stack(store, cost, dir, STACK_A);
	pb(store);
}

void	ft_manage_rra2(t_store *store, int cost, int dir, int mean)
{
	if (store->stack_b->value < mean
		&& (store->stack_b->flag == store->chunk_num - 1))
		rb(store, STACK_B);
	ft_rotate_stack(store, cost, dir, STACK_A);
	pb(store);
}

void	ft_push_the_rest(t_store *store, int count, int chunk_index)
{
	int		cost;
	int		dir;
	int		mean;
	bool	rr_flag;

	mean = ft_chunk_sum(store->stack_a, chunk_index) / store->chunk_size;
	while (count--)
	{
		ft_index(store->stack_a, 0);
		cost = ft_get_dir_a(store, chunk_index, 0, &dir);
		if (dir == UP && rr_flag == true && cost > 1)
			ft_manage_rr(store, cost, dir);
		else if (dir == UP && cost == 1)
		{
			if (store->stack_b->value < mean)
				rb(store, STACK_B);
			pb(store);
		}
		else
			ft_manage_rra2(store, cost, dir, mean);
		if (store->stack_b->value < mean)
			rr_flag = true;
		else
			rr_flag = false;
	}
}
