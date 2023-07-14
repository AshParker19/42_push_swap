/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:39:59 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 21:35:44 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	b_rb(t_store *store)
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
	}
}

void	b_rr(t_store *store)
{
	b_ra(store);
	b_rb(store);
}

void	b_rra(t_store *store)
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
	}
}

void	b_rrb(t_store *store)
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
	}
}

void	b_rrr(t_store *store)
{
	b_rra(store);
	b_rrb(store);
}
