/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:56:22 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/18 23:38:52 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

// errors
# define SORTED_ALREADY  0
# define NOT_NUMERIC 	 1
# define INVALID_INT 	 2

// stacks flags
# define NEUTRAL		 0
# define STACK_A 		 1
# define STACK_B 		 2

// numbers
# define EVEN			 0
# define ODD			 1

// colors for testing
# define GREEN 			"\033[0;32m"
# define RED 			"\033[0;31m"
# define YELLOW 		"\x1b[33m"
# define CYAN 			"\x1b[36m"
# define PURPLE 		"\x1b[35m"
# define SALMON			"\033[38;5;209m"
# define SBLUE			"\033[38;5;117m"
# define RESET 			"\033[0m"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_store
{
	int		count;
	int		min_even;
	int		max_even;
	int		min_odd;
	int		max_odd;
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_store;

// llists
void		ft_create_stack(int ac, char *av[]);
t_stack		*ft_addback(t_stack *head, int new_value);
void		ft_print_list(t_store *store);
t_stack		*ft_free_stack(t_stack *s_a);

// operations
void		sa_sb(t_stack *head, int flag);
void		ss(t_stack *s_a, t_stack *s_b);
void		pa_pb(t_store *store, t_stack **push_from, t_stack **push_to, int flag);
void		ra_rb(t_stack *head, int flag);
void		rr(t_stack *s_a, t_stack *s_b);
void		rra_rrb(t_stack *head, int flag);
void		rrr(t_stack *s_a, t_stack *s_b);

// sort 
void		ft_sort(t_store *store);
void		ft_min_max_search(t_store *store, t_stack *stack_a, int i);
int	ft_find_position(t_stack *stack_a, int to_find);

// utils
int			ft_valid(int ac, char *av[]);
int			ft_checker(int ac, char *av[]);
int			ft_checker2(int ac, char *av[]);
int			ft_numeric(char *str);
void		ft_putstr(char *str);
int			ft_check_if_sorted(t_stack *head);
void		ft_reset_limits(t_store *store);
int			ft_find_the_cost(int index, int count);
int			ft_get_direction(t_store *store, int min_value, int max_value);

// ternary
char		*ft_ternary(int condition, char *expression1, char *expression2);
int			ft_num_ternary(int condition, int expression1, int expression2);

// libft
long int	ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);

#endif

