/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:00:34 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/11 21:24:48 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	if (ac == 1 || (ac == 2 && ft_numeric(av[1])
			&& (ft_atoi(av[1]) > INT_MIN && ft_atoi(av[1]) < INT_MAX)))
		exit (0);
	else
		if (ft_checker(ac, av))
			ft_create_stack(ac, av);
}
