/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:12:37 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/18 21:15:19 by anshovah         ###   ########.fr       */
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

void	ss(t_stack *s_a, t_stack *s_b)
{
	sa_sb(s_a, NEUTRAL);
	sa_sb(s_b, NEUTRAL);
	ft_putstr("ss\n");
}

void	pa_pb(t_store *store, t_stack **push_from, t_stack **push_to, int flag)
{
	t_stack	*temp;

	if (*push_from)
	{
		temp = *push_from;
		if (!(*push_from)->next)
			*push_from = NULL;
		else
		{
			*push_from = (*push_from)->next;
			(*push_from)->prev = NULL;
		}
		temp->next = *push_to;
		if (*push_to)
			(*push_to)->prev = temp;
		*push_to = temp;
		if (flag)
			ft_putstr(ft_ternary(flag == STACK_A,
					"pb\n", "pa\n"));
		if (flag == STACK_A)
			store->count -= 1;
		ft_reset_limits(store);			
	}
}

void	ra_rb(t_stack *head, int flag)
{
	t_stack	*current;
	int		first_orig;

	current = head;
	if (head)
	{
		first_orig = head->value;
		while (current->next)
		{
			current->value = current->next->value;
			current = current->next;
		}
		current->value = first_orig;
		if (flag)
			ft_putstr(ft_ternary(flag == STACK_A,
					"ra\n", "rb\n"));
	}
}

void	rr(t_stack *s_a, t_stack *s_b)
{
	ra_rb(s_a, NEUTRAL);
	ra_rb(s_b, NEUTRAL);
	ft_putstr("rr\n");
}
