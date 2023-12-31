/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:00:34 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 14:57:53 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	if (ac == 2)
		ft_start_from_quotes(av[1]);
	else
		if (ft_checker(ac, av))
			ft_create_stack(ac, av, 0, 0);
}

/******************************************************************************/
/*  __       _______ .___________.__     _______.     _______   ______    __  */
/* |  |     |   ____||           (_ )   /       |    /  _____| /  __  \  |  | */
/* |  |     |  |__   `---|  |----`|/   |   (----`   |  |  __  |  |  |  | |  | */
/* |  |     |   __|      |  |           \   \       |  | |_ | |  |  |  | |  | */
/* |  `----.|  |____     |  |       .----)   |      |  |__| | |  `--'  | |__| */
/* |_______||_______|    |__|       |_______/        \______|  \______/  (__) */
/*                                                                            */
/******************************************************************************/