/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:24:27 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 21:23:19 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void    ft_initialize(t_store *store)
{
	store->stack_a = NULL;
	store->stack_b = NULL;
	store->tail_a = NULL;
	store->tail_b = NULL;
    store->count_a = 0;
	store->count_b = 0;
}

t_stack	*ft_free_stack(t_stack *stack_a)
{
	if (stack_a)
	{
		ft_free_stack(stack_a->next);
		free (stack_a);
	}
	return (NULL);
}

t_stack	*ft_addback(t_store *store, int new_value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	new->value = new_value;
	if (!store->stack_a)
	{
		store->tail_a = new;
		return (new);
	}
	else
	{
		store->tail_a->next = new;
		new->prev = store->tail_a;
		store->tail_a = new;
		return (store->stack_a);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	c1 = s1[i];
	c2 = s2[i];
	return (c1 - c2);
}
