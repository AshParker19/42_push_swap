/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:38:02 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 21:35:32 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	b_sa_sb(t_stack *stack)
{
	int	temp;

	if (stack && stack->next)
	{
		temp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = temp;
	}
}

void	b_ss(t_store *store)
{
	b_sa_sb(store->stack_a);
	b_sa_sb(store->stack_b);
}

void	b_pb(t_store *store)
{
	t_stack	*temp;

	if (store->stack_a)
	{
		temp = store->stack_a;
		if (!store->stack_a->next)
			store->stack_a = NULL;
		else
		{
			store->stack_a = store->stack_a->next;
			store->stack_a->prev = NULL;
		}
		temp->next = store->stack_b;
		if (store->stack_b)
			store->stack_b->prev = temp;
		store->stack_b = temp;
		store->count_a -= 1;
		store->count_b += 1;
		if (store->count_b == 1)
			store->tail_b = store->stack_b;
		else if (store->count_a == 0)
			store->tail_a = NULL;
	}
}

void	b_pa(t_store *store)
{
	t_stack	*temp;

	if (store->stack_b)
	{
		temp = store->stack_b;
		if (!store->stack_b->next)
			store->stack_b = NULL;
		else
		{
			store->stack_b = store->stack_b->next;
			store->stack_b->prev = NULL;
		}
		temp->next = store->stack_a;
		if (store->stack_a)
			store->stack_a->prev = temp;
		store->stack_a = temp;
		store->count_a += 1;
		store->count_b -= 1;
		if (store->count_a == 1)
			store->tail_a = store->stack_a;
		else if (store->count_b == 0)
			store->tail_b = NULL;
	}
}

void	b_ra(t_store *store)
{
	t_stack	*temp;

	if (store->stack_a && store->stack_a->next)
	{
		temp = store->stack_a;
		store->stack_a = store->stack_a->next;
		store->stack_a->prev = NULL;
		store->tail_a->next = temp;
		temp->prev = store->tail_a;
		temp->next = NULL;
		store->tail_a = temp;
	}
}
