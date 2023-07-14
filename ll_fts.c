/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_fts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:13:54 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 13:44:27 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(int ac, char *av[], int i, int j)
{
	t_store		store;
	int			*copy;

	copy = ft_calloc(ac - 1, sizeof(int));
	if (!copy)
		return ;
	ft_initialize_store(&store, ac - 1);
	while (++i < ac - j)
		store.stack_a = ft_addback(&store, ft_atoi(av[i]));
	ft_sort_main(&store, copy);
	store.stack_a = ft_free_stack_a(store.stack_a);
	free (copy);
}

void	ft_initialize_store(t_store *store, int count_a)
{
	store->stack_a = NULL;
	store->stack_b = NULL;
	store->tail_a = NULL;
	store->tail_b = NULL;
	store->count_a = count_a;
	store->count_b = 0;
	if (count_a == 100)
	{
		store->chunk_size = 12;
		store->chunk_num = 8;
	}
	else if (count_a == 500)
	{
		store->chunk_size = 35;
		store->chunk_num = 14;
	}
	else
	{
		store->chunk_size = store->count_a / 10;
		store->chunk_num = 10;
	}
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

t_stack	*ft_free_stack_a(t_stack *stack_a)
{
	if (stack_a)
	{
		ft_free_stack_a(stack_a->next);
		free (stack_a);
	}
	return (NULL);
}
