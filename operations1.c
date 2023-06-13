/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:12:37 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/13 17:23:12 by anshovah         ###   ########.fr       */
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
		{
			if (flag == STACK_A)
				ft_putstr("sa\n");
			else
				ft_putstr("sb\n");
		}
	}
}

void	ss(t_stack *s_a, t_stack *s_b)
{
	sa_sb(s_a, 0);
	sa_sb(s_b, 0);
	ft_putstr("ss\n");
}

void	pa_pb(t_stack **push_from, t_stack **push_to, int flag)
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
		{
			if (flag == STACK_A)
				ft_putstr("pb\n");
			else
				ft_putstr("pa\n");
		}
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
		{
			if (flag == STACK_A)
				ft_putstr("ra\n");
			else
				ft_putstr("rb\n");
		}
	}
}

void	rr(t_stack *s_a, t_stack *s_b)
{
	ra_rb(s_a, 0);
	ra_rb(s_b, 0);
	ft_putstr("rr\n");
}
