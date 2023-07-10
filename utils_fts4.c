/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fts4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:07:16 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/09 22:13:30 by anshovah         ###   ########.fr       */
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

// void	ft_manage_stack_a(t_store *store)
// {
// 	int	cost;
// 	int	dir;
// 	int flag1 = 1;
// 	int flag2 = 2;
// 	int	flag_cnt1;
// 	int	flag_cnt2;

// 	while (store->stack_a)
// 	{
// 		ft_index(store->stack_a, 0);
// 		flag_cnt1 = ft_count_flags(store->stack_a, flag1);
// 		if (flag_cnt1 == 0)
// 			flag1 += 2;
// 		flag_cnt2 = ft_count_flags(store->stack_a, flag2);
// 		if (flag_cnt2 == 0)
// 			flag2 += 2;
// 		if (flag_cnt1 && flag_cnt2)
// 			cost = ft_get_dir_a(store, flag1, flag2, &dir);
// 		else if (flag_cnt1 && !flag_cnt2)
// 			cost = ft_get_dir_a(store, flag1, 0, &dir);
// 		else if (!flag_cnt1 && flag_cnt2)
// 			cost = ft_get_dir_a(store, 0, flag2, &dir);
// 		ft_rotate_stack(store, cost, dir, STACK_A);
// 		pb(store);
// 		if (store->stack_b->flag == flag2)
// 			rb(store, STACK_B);	
// 	}
// }