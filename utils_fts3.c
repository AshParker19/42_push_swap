/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:19:55 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/05 13:12:51 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_from_start(t_stack *stack_a, int find_flag)
{
	if (!stack_a)
		return (-1);
	if (stack_a->flag == find_flag)
	{
		return (stack_a->index);
	}
	else
		return (ft_from_start(stack_a->next, find_flag));
}

int	ft_from_end(t_stack *tail_a, int find_flag)
{
	if (!tail_a)
		return (-1);
	if (tail_a->flag == find_flag)
	{
		return (tail_a->index);
	}
	else
		return (ft_from_end(tail_a->prev, find_flag));
}

int	ft_get_dir_a(t_store *store, int flag1, int flag2, int *dir)
{
	int	flag1_cost;
	int	flag2_cost;
	int	final_num;
	int	dir_save;

	final_num = 0;
	if (flag1 && flag2)
	{
		flag1_cost = ft_closer(store, flag1, dir);
		dir_save = *dir;
		flag2_cost = ft_closer(store, flag2, dir);
		if (flag1_cost <= flag2_cost)
		{
			*dir = dir_save;
			return (flag1_cost);
		}
		else
			return (flag2_cost);
	}
	else if (flag1 && !flag2)
		final_num = ft_closer(store, flag1, dir);
	else if (!flag1 && flag2)
		final_num = ft_closer(store, flag2, dir);
	return (final_num);
}

void	ft_1st_2nd(t_store *store, t_stack *stack_b, int i)
{
	if (!stack_b)
		return ;
	if (stack_b->value > store->biggest)
	{
		store->snd_biggest = store->biggest;
		store->biggest = stack_b->value;
	}
	else if (stack_b->value > store->snd_biggest)
		store->snd_biggest = stack_b->value;
	stack_b->index = i;
	ft_1st_2nd(store, stack_b->next, i + 1);
}

int	ft_find_position(t_stack *stack_b, int to_find)
{
	if (!stack_b)
		return (0);
	if (stack_b->value == to_find)
		return (stack_b->index);
	else
		return (ft_find_position(stack_b->next, to_find));
}
