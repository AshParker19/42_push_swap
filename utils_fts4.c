/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:07:16 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/11 22:34:43 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_dir_b(t_store *store, int value, int *dir)
{
	return (ft_find_the_cost(ft_find_position(store->stack_b, value),
			store->count_b, dir));
}

int	ft_find_the_cost2(t_store *store, int *dir, int *to_push)
{
	int	cost1;
	int	cost2;
	int	dir_copy;

	cost1 = ft_get_dir_b(store, store->biggest, dir);
	dir_copy = *dir;
	cost2 = ft_get_dir_b(store, store->snd_biggest, dir);
	if (cost1 <= cost2)
	{
		*to_push = BIGGEST;
		*dir = dir_copy;
		return (cost1);
	}
	else
	{
		*to_push = SND_BIGGEST;
		return (cost2);
	}
}

int	ft_chunk_sum(t_stack *stack_a, int find_flag)
{
	if (!stack_a)
		return (0);
	if (stack_a->flag == find_flag)
		return (stack_a->value
			+ ft_chunk_sum(stack_a->next, find_flag));
	else
		return (ft_chunk_sum(stack_a->next, find_flag));
}


void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = -1;
// 	while (s[++i])              use this!!!!!!!!!
// 		write(fd, &s[i], 1);
// }
