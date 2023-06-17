/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:20:21 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/17 15:24:52 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_ternary(int condition, char *expression1, char *expression2)
{
	if (condition)
		return (expression1);
	else
		return (expression2);
}

int		ft_num_ternary(int condition, int expression1, int expression2)
{
	if (condition)
		return (expression1);
	else
		return (expression2);
}
