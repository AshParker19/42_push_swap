/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:00:34 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/13 19:35:34 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	if (ft_valid(ac, av))
		exit (SORTED_ALREADY);
	else
		if (ft_checker(ac, av))
			ft_create_stack(ac, av);
}
