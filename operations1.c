/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:12:37 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/11 21:37:38 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *head)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->value;
		head->value = head->next->value;
		head->next->value = temp;
	}
}

void	ss(t_stack *s_a, t_stack *s_b)
{
	sa_sb(s_a);
	sa_sb(s_b);
}

void	pa(t_stack **s_a, t_stack **s_b)
{
	t_stack	*temp;

	if (*s_b)
	{
		temp = *s_b;
		if (!(*s_b)->next)
			*s_b = NULL;
		else
		{
			*s_b = (*s_b)->next;
			(*s_b)->prev = NULL;
		}
		temp->next = *s_a;
		if (*s_a)
			(*s_a)->prev = temp;
		*s_a = temp;
	}
}

void	pb(t_stack **s_a, t_stack **s_b)
{
	t_stack	*temp;

	if (*s_a)
	{
		temp = *s_a;
		if (!(*s_a)->next)
			*s_a = NULL;
		else
		{
			*s_a = (*s_a)->next;
			(*s_a)->prev = NULL;
		}
		temp->next = *s_b;
		if (*s_b)
			(*s_b)->prev = temp;
		*s_b = temp;
	}
}

void	ra_rb(t_stack *head)
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
	}
}
