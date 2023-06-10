/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:56:51 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/10 14:33:39 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *s1, t_stack *s2)
{
	ra_rb(s1);
	ra_rb(s2);
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

void	rrr(t_stack *s1, t_stack *s2)
{
	rra_rrb(s1);
	rra_rrb(s2);
}