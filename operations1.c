/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:12:37 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/01 23:20:59 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *head, int flag)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->value;
		head->value = head->next->value;
		head->next->value = temp;
		if (flag)
			ft_putstr(ft_ternary(flag == STACK_A,
					"sa\n", "sb\n"));
	}
}

void	ss(t_store *store)
{
	sa_sb(store->stack_a, NEUTRAL);
	sa_sb(store->stack_b, NEUTRAL);
	ft_putstr("ss\n");
}

void	pb(t_store *store)
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
		ft_putstr("pb\n");
	}
}

void	pa(t_store *store)
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
		ft_putstr("pa\n");
	}
}

void	ra(t_store *store, int flag)
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
		if (flag == STACK_A)
			ft_putstr("ra\n");
	}
}
