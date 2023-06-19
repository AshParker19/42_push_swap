/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:48:20 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/19 14:06:47 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_store *store)
{
	if (store->count == 2)
		sa_sb(store->stack_a, STACK_A);
	else
		ft_algorithm(store);
}
