/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:12:37 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/10 14:17:44 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *head)
{
	int temp;

	if (head && head->next)
	{
		temp = head->value;
		head->value = head->next->value;
		head->next->value = temp;	
	}
}

void	pa(t_stack **s_a, t_stack **s_b)
{
	t_stack *temp;
	
	if (*s_b)
	{
		if (!(*s_b)->next)
		{
			*s_a = ft_addfront(*s_a, (*s_b)->value);
			*s_b = NULL;
			free (*s_b);
		}
		else
		{
			*s_a = ft_addfront(*s_a, (*s_b)->value);
			temp = *s_b;
			*s_b = (*s_b)->next;
			(*s_b)->prev = NULL;
			free (temp);
		}
	}
}

void	pb(t_stack **s_a, t_stack **s_b)
{
	t_stack	*temp;
	
	if (*s_a)
	{
		if (!(*s_a)->next)
		{
			*s_b = ft_addfront(*s_b, (*s_a)->value);
			*s_a = NULL;
			free (*s_a);
		}
		else
		{
			*s_b = ft_addfront(*s_b, (*s_a)->value);
			temp = *s_a;
			*s_a = (*s_a)->next;
			(*s_a)->prev = NULL;
			free (temp);
		}
	}	
}

void	ss(t_stack *s1, t_stack *s2)
{
	sa_sb(s1);
	sa_sb(s2);
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