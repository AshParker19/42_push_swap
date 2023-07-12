/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:44:26 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/12 13:47:14 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b_main(t_store *store)
{
	int	first;
	int	second;
	int	push_pair;

	first = 1;
	second = 2;
	push_pair = (store->chunk_num - 2) / 2;
	while (push_pair--)
	{
		ft_push_pairs(store, first, second,
			store->chunk_size * 2);
		first += 2;
		second += 2;
	}
	ft_push_the_rest(store, store->chunk_size, store->chunk_num - 1);
	ft_push_the_rest(store, store->chunk_size, store->chunk_num);
}

void	ft_push_pairs(t_store *store, int bottom_flag, int top_flag, int count)
{
	int		cost;
	int		dir;
	bool	rr_flag;

	while (count--)
	{
		ft_index(store->stack_a, 0);
		cost = ft_manage_details(store, bottom_flag, top_flag, &dir);
		if (store->stack_b && dir == UP && rr_flag == true && cost > 1)
			ft_manage_rr(store, cost, dir);
		else if (store->stack_b && dir == UP && cost == 1)
			ft_manage_top_a(store, bottom_flag);
		else
			ft_manage_rra(store, cost, dir, bottom_flag);
		if (store->stack_b->flag == bottom_flag)
			rr_flag = true;
		else
			rr_flag = false;
	}
}

int	ft_manage_details(t_store *store, int bottom_flag, int top_flag, int *dir)
{
	int	flag_cnt1;
	int	flag_cnt2;

	flag_cnt1 = ft_count_flags(store->stack_a, bottom_flag);
	flag_cnt2 = ft_count_flags(store->stack_a, top_flag);
	if (flag_cnt1 && flag_cnt2)
		return (ft_get_dir_a(store, bottom_flag, top_flag, dir));
	else if (flag_cnt1 && !flag_cnt2)
		return (ft_get_dir_a(store, bottom_flag, 0, dir));
	else if (!flag_cnt1 && flag_cnt2)
		return (ft_get_dir_a(store, 0, top_flag, dir));
	return (0);
}

void	ft_manage_rr(t_store *store, int cost, int dir)
{
	rr(store);
	cost -= 1;
	ft_rotate_stack(store, cost, dir, STACK_A);
	pb(store);
}

void	ft_manage_top_a(t_store *store, int bottom_flag)
{
	if (store->stack_b->flag == bottom_flag
		|| store->stack_b->flag == bottom_flag - 2)
		rb(store, STACK_B);
	pb(store);
}
