/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:24:27 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/17 14:36:42 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_make_stack(int ac, char *av[], int i)
{
	t_store	store;

	ft_initialize(&store);
	while (++i < ac)
		store.stack_a = ft_addback(&store, ft_atoi(av[i]));
	ft_read_commands(&store);
	store.stack_a = ft_free_stack(store.stack_a);
}

void	ft_initialize(t_store *store)
{
	store->stack_a = NULL;
	store->stack_b = NULL;
	store->tail_a = NULL;
	store->tail_b = NULL;
	store->count_a = 0;
	store->count_b = 0;
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

t_stack	*ft_free_stack(t_stack *stack_a)
{
	if (stack_a)
	{
		ft_free_stack(stack_a->next);
		free (stack_a);
	}
	return (NULL);
}

void	ft_read_commands(t_store *store)
{
	char	*op;
	char	**ops_store;

	ops_store = ft_initialize_ops();
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		if (!ft_validate_operation(op, ops_store))
		{
			ft_free_everything(store, ops_store);
			free (op);
			ft_putstr_fd("Error\n", 2);
			exit (INVALID_OPERATION);
		}
		else
			ft_do_op(store, op);
		free (op);
	}
	ft_conclusion(store, ops_store);
}
