/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:45:29 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/05 20:24:17 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_manage_stack_a(t_store *store, int flag1, int flag2, int count)
{
	int	cost;
	int	dir;
	int	flag_cnt1;
	int	flag_cnt2;

	while (count--)
	{
		ft_index(store->stack_a, 0);
		flag_cnt1 = ft_count_flags(store->stack_a, flag1);
		flag_cnt2 = ft_count_flags(store->stack_a, flag2);
		if (flag_cnt1 && flag_cnt2)
			cost = ft_get_dir_a(store, flag1, flag2, &dir);
		else if (flag_cnt1 && !flag_cnt2)
			cost = ft_get_dir_a(store, flag1, 0, &dir);
		else if (!flag_cnt1 && flag_cnt2)
			cost = ft_get_dir_a(store, 0, flag2, &dir);
		ft_rotate_stack(store, cost, dir, STACK_A);
		pb(store);
		if (store->stack_b->flag == flag2)
			rb(store, STACK_B);
	}
}

void	ft_push_to_b(t_store *store)
{
	int	chunk1;
	int	chunk2;
	int	push_chunks;

	chunk1 = 1;
	chunk2 = 2;
	push_chunks = 5;
	while (push_chunks--)
	{
		ft_manage_stack_a(store, chunk1, chunk2,
					store->chunk_size * 2);
		chunk1 += 2;
		chunk2 += 2;
	}	
}

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
	int	cost;
	int	to_push;
	int was_pushed;
	
	while (store->stack_b)
	{
		store->biggest = INT_MIN;
		ft_1st_2nd(store, store->stack_b, 0);
		cost = ft_find_the_cost2(store, &dir, &to_push);
		ft_rotate_stack(store, cost, dir, STACK_B);
		if (first-- == 1)
			pa(store);
		////////////
		if (store->stack_b->value == store->snd_biggest
			&& store->stack_b->next->value == store->biggest)
		{
			sa_sb(store->stack_b, STACK_B);
			continue;
		}	
	
		if (was_pushed == BIGGEST)
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
	ft_push_to_b(store);
	ft_push_to_a(store, 0, 1, 0);
	// ft_print_list(store);
}

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