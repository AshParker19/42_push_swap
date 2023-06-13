/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:56:22 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/13 18:24:48 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

// errors
# define SORTED_ALREADY 0
# define NOT_NUMERIC 	1
# define INVALID_INT 	2

// stacks flags
# define STACK_A 		1
# define STACK_B 		2

// colors for testing
# define GREEN 			"\033[0;32m"
# define RED 			"\033[0;31m"
# define YELLOW 		"\x1b[33m"
# define CYAN 			"\x1b[36m"
# define PURPLE 		"\x1b[35m"
# define RESET 			"\033[0m"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_store
{
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_store;

// llists
void		ft_create_stack(int ac, char *av[]);
t_stack		*ft_addback(t_stack *head, int new_value);
void		ft_print_list(t_stack *s1, t_stack *s2);
t_stack		*ft_free_stack(t_stack *s_a);

// operations
void		sa_sb(t_stack *head, int flag);
void		ss(t_stack *s_a, t_stack *s_b);
void		pa_pb(t_stack **push_from, t_stack **push_to, int flag);
void		ra_rb(t_stack *head, int flag);
void		rr(t_stack *s_a, t_stack *s_b);
void		rra_rrb(t_stack *head, int flag);
void		rrr(t_stack *s_a, t_stack *s_b);

// sort 
void	ft_sort(t_store store);

// utils
int			ft_valid(int ac, char *av[]);
int			ft_checker(int ac, char *av[]);
int			ft_checker2(int ac, char *av[]);
int			ft_numeric(char *str);
void		ft_putstr(char *str);
int			ft_check_if_sorted(t_stack *head);

// libft
long int	ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);

#endif