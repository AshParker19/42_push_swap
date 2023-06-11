/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:56:51 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/11 21:23:55 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *s_a, t_stack *s_b)
{
	ra_rb(s_a);
	ra_rb(s_b);
}

void	rra_rrb(t_stack *head)
{
	t_stack	*current;
	int		last_orig;

	current = head;
	if (head)
	{
		while (current->next)
			current = current->next;
		last_orig = current->value;
		while (current->prev)
		{
			current->value = current->prev->value;
			current = current->prev;
		}
		current->value = last_orig;
	}
}

void	rrr(t_stack *s_a, t_stack *s_b)
{
	rra_rrb(s_a);
	rra_rrb(s_b);
}
