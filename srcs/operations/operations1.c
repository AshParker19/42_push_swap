/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:12:37 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 14:56:55 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa_sb(t_stack *stack, int flag)
{
	int	temp;

	if (stack && stack->next)
	{
		temp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = temp;
		if (flag == STACK_A)
			ft_putstr_fd("sa\n", 1);
		else if (flag == STACK_B)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_store *store)
{
	sa_sb(store->stack_a, NEUTRAL);
	sa_sb(store->stack_b, NEUTRAL);
	ft_putstr_fd("ss\n", 1);
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
		ft_putstr_fd("pb\n", 1);
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
		ft_putstr_fd("pa\n", 1);
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
			ft_putstr_fd("ra\n", 1);
	}
}
