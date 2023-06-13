/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:56:51 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/13 17:23:30 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_stack *head, int flag)
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
		if (flag)
		{
			if (flag == STACK_A)
				ft_putstr("rra\n");
			else
				ft_putstr("rrb\n");
		}
	}
}

void	rrr(t_stack *s_a, t_stack *s_b)
{
	rra_rrb(s_a, 0);
	rra_rrb(s_b, 0);
	ft_putstr("rrr\n");
}
