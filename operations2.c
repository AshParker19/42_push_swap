/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:56:51 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/19 19:12:20 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_store *store, t_stack *head, int flag)
{
	t_stack	*current;
	int		last_orig;

	current = head;
	if (head)
	{
		while (current->next)
			current = current->next;
		if (flag == STACK_B)
			store->tail_b = current;
		last_orig = current->value;
		while (current->prev)
		{
			current->value = current->prev->value;
			current = current->prev;
		}
		current->value = last_orig;
		if (flag)
			ft_putstr(ft_ternary(flag == STACK_A,
					"rra\n", "rrb\n"));
	}
}

// void	rra_rrb(t_stack *head, int flag)
// {
// 	t_stack	*current;
// 	int		last_orig;

// 	current = head;
// 	if (head)
// 	{
// 		while (current->next)
// 			current = current->next;
// 		last_orig = current->value;
// 		while (current->prev)
// 		{
// 			current->value = current->prev->value;
// 			current = current->prev;
// 		}
// 		current->value = last_orig;
// 		if (flag)
// 			ft_putstr(ft_ternary(flag == STACK_A,
// 					"rra\n", "rrb\n"));
// 	}
// }

void	rrr(t_store *store, t_stack *s_a, t_stack *s_b)
{
	rra_rrb(store, s_a, NEUTRAL);
	rra_rrb(store, s_b, NEUTRAL);
	ft_putstr("rrr\n");
}
