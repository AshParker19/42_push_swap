/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:13:51 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/13 15:56:54 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_a(t_store *store, int count, int first, int dir)
{
	int		cost;
	int		to_push;
	int		was_pushed;

	while (store->stack_b)
	{
		store->biggest = INT_MIN;
		ft_1st_2nd(store, store->stack_b, 0);
		cost = ft_find_the_cost2(store, &dir, &to_push);
		ft_rotate_stack(store, cost, dir, STACK_B);
		if (ft_manage_sb(store))
			continue ;
		if (first-- == 1)
			pa(store);
		else if (was_pushed == BIGGEST)
			pa(store);
		else if (was_pushed == SND_BIGGEST)
			ft_manage_snd_biggest(store, &count, to_push);
		was_pushed = to_push;
	}
}

void	ft_manage_snd_biggest(t_store *store, int *count, int to_push)
{
	if (*count == 0)
		*count = *count + 1;
	if (to_push == BIGGEST)
	{
		ft_rollback(store, *count);
		*count = 0;
	}
	else if (to_push == SND_BIGGEST)
	{
		pa(store);
		*count = *count + 1;
	}
}

int	ft_manage_sb(t_store *store)
{
	if (store->stack_b->value == store->snd_biggest
		&& store->stack_b->next->value == store->biggest)
	{
		sa_sb(store->stack_b, STACK_B);
		return (1);
	}
	else
		return (0);
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
