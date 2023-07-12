/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:45:29 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/12 13:47:32 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rollback(t_store *store, int ra_count)
{
	int	rra_count;

	rra_count = ra_count;
	if (ra_count == 1)
	{
		pa(store);
		sa_sb(store->stack_a, STACK_A);
	}
	else
	{
		while (ra_count)
		{
			ra(store, STACK_A);
			ra_count--;
		}
		pa(store);
		while (rra_count)
		{
			rra(store, STACK_A);	
			rra_count--;
		}
	}
}

void	ft_push_to_a(t_store *store, int count, int first, int dir)
{
	int		cost;
	int		to_push;
	int 	was_pushed;
	
	while (store->stack_b)
	{
		store->biggest = INT_MIN;
		ft_1st_2nd(store, store->stack_b, 0);
		cost = ft_find_the_cost2(store, &dir, &to_push);
		ft_rotate_stack(store, cost, dir, STACK_B);
		//////////////////
		if (store->stack_b->value == store->snd_biggest
			&& store->stack_b->next->value == store->biggest)
		{
			sa_sb(store->stack_b, STACK_B);
			continue;
		}	
		/////////////////	
		if (first-- == 1)
			pa(store);
		else if (was_pushed == BIGGEST)
			pa(store);
		else if (was_pushed == SND_BIGGEST)
		{
			if (count == 0)
				count++;
			if (to_push == BIGGEST)
			{
				ft_rollback(store, count);
				count = 0;
			}
			else if (to_push == SND_BIGGEST)
			{
				pa(store);
				count++;
			}
		}
		was_pushed = to_push;
	}
}

void	ft_algorithm(t_store *store, int copy[])
{
	ft_copy_values(store->stack_a, copy, 0);
	ft_sort_copy(copy, store->count_a);
	ft_index(store->stack_a, 0);
	ft_marker(store, store->stack_a, copy, 1);
	
	// ft_push_to_b(store);
	ft_push_b_main(store);

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









// check the value at the top of SB and the one next to it
//  if the second one is the biggest or second biggest, swap
//  the top of SB instead of rotation

// check the value at the top of SB, if the one to be pushed is second
// big, but the next one is the biggest one, swap them insted of rotating and
// push the biggest one, so we don't need to rotate SA and then rotate it back

// always ise swaps

// if the prev that was pushed to sb needed to be rotated
// 	 if rotation happens on SA
// 		do double rotation

// do double reverse rotation while pushing back to SA
// it can save lots of moves cause if SA was rotated and it will be needed rotated back
// it will be 2 reverse rottaion of SA at least. check how many rrotations of SB needed
// do max possible number of double rrr and the rotate the rest with usual rrb