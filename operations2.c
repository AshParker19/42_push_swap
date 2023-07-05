/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:56:51 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/05 12:57:39 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_store *store, int flag)
{
	t_stack	*temp;

	if (store->stack_b && store->stack_b->next)
	{
		temp = store->stack_b;
		store->stack_b = store->stack_b->next;
		store->stack_b->prev = NULL;
		store->tail_b->next = temp;
		temp->prev = store->tail_b;
		temp->next = NULL;
		store->tail_b = temp;
		if (flag == STACK_B)
			ft_putstr("rb\n");
	}
}

void	rr(t_store *store)
{
	ra(store, NEUTRAL);
	rb(store, NEUTRAL);
	ft_putstr("rr\n");
}

void	rra(t_store *store, int flag)
{
	t_stack	*temp;

	if (store->stack_a && store->stack_a->next)
	{
		temp = store->tail_a;
		store->tail_a = store->tail_a->prev;
		store->tail_a->next = NULL;
		store->stack_a->prev = temp;
		temp->prev = NULL;
		temp->next = store->stack_a;
		store->stack_a = temp;
		if (flag == STACK_A)
			ft_putstr("rra\n");
	}
}

void	rrb(t_store *store, int flag)
{
	t_stack	*temp;

	if (store->stack_b && store->stack_b->next)
	{
		temp = store->tail_b;
		store->tail_b = store->tail_b->prev;
		store->tail_b->next = NULL;
		store->stack_b->prev = temp;
		temp->prev = NULL;
		temp->next = store->stack_b;
		store->stack_b = temp;
		if (flag == STACK_B)
			ft_putstr("rrb\n");
	}
}

void	rrr(t_store *store)
{
	rra(store, NEUTRAL);
	rrb(store, NEUTRAL);
	ft_putstr("rrr\n");
}
