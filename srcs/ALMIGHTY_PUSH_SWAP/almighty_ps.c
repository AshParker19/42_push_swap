/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almighty_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:45:29 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/16 12:27:41 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_almighty_ps(t_store *store, int copy[])
{
	ft_copy_values(store->stack_a, copy, 0);
	ft_sort_copy(copy, store->count_a);
	ft_marker(store, store->stack_a, copy, 1);
	ft_push_b_main(store);
	ft_sort_the_remainder(store);
	ft_push_to_a(store, 0, 1, 0);
}
