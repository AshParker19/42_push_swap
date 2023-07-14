/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:08:27 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 21:30:45 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "../bonus/get_next_line/get_next_line.h"

# define INVALID_OPERATION 1

// checker 
void		ft_make_stack(int ac, char *av[], int i);
void		ft_read_commands(t_store *store);
void		ft_initialize(t_store *store);
char		**ft_initialize_ops(void);
int			ft_validate_operation(char *op, char **ops_store);
void		ft_do_op(t_store *store, char *op);
void		ft_conclusion(t_store *store, char **ops_store);
int			ft_result(t_stack *stack_a);

// llists
t_stack		*ft_addback(t_store *store, int new_value);
t_stack		*ft_free_stack(t_stack *stack_a);

// utils
int			ft_valid(int ac, char *av[]);
void		ft_free_everything(t_store *store, char **ops_store);
int			ft_strcmp(char *s1, char *s2);

// operations without printing
void		b_sa_sb(t_stack *stack);
void		b_ss(t_store *store);
void		b_pb(t_store *store);
void		b_pa(t_store *store);
void		b_ra(t_store *store);
void		b_rb(t_store *store);
void		b_rr(t_store *store);
void		b_rra(t_store *store);
void		b_rrb(t_store *store);
void		b_rrr(t_store *store);

#endif