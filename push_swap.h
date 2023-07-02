/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:56:22 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/02 23:08:14 by anshovah         ###   ########.fr       */
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

// directions
# define UP				 11
# define DOWN			 12

// range
# define BIGGEST		 13
# define SND_BIGGEST	 14

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
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_store
{
	int		count_a;
	int		count_b;
	int		chunk_size;
	int		percent10;
	int		biggest;
	int		snd_biggest;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tail_a;
	t_stack	*tail_b;
}				t_store;

// linked lists fts
void		ft_create_stack(int ac, char *av[]);
t_stack		*ft_addback(t_store *store, int new_value);
void		ft_print_list(t_store *store);
t_stack		*ft_free_stack_a(t_stack *stack_a);

// operations 
void		sa_sb(t_stack *head, int flag);
void		ss(t_store *store);
void		pb(t_store *store);
void		pa(t_store *store);
void		ra(t_store *store, int flag);
void		rb(t_store *store, int flag);
void		rr(t_store *store);
void		rra(t_store *store, int flag);
void		rrb(t_store *store, int flag);
void		rrr(t_store *store);

// sort 
void		ft_sort(t_store *store, int copy[]);
void		ft_algorithm(t_store *store, int copy[]);
void		ft_index(t_stack *stack_a, int i);
int			ft_find_position(t_stack *stack_a, int to_find);
// int			ft_find_the_cost(int index, int count);
int	ft_find_the_cost(int index, int count, int *dir);
int	ft_get_direction(t_store *store, int value, int *dir);
// int			ft_get_direction(t_store *store, int min_value, int max_value, int *dir);
void	ft_rotate_stack(t_store *store, int cost, int dir_flag);
int		ft_find_pos_array(int copy[], int size, int to_find, int i);


// parsing
int			ft_valid(int ac, char *av[]);
int			ft_checker(int ac, char *av[]);
int			ft_checker2(int ac, char *av[]);
int			ft_numeric(char *str);
int			ft_check_if_sorted(t_stack *head);

// utils
char		*ft_ternary(int condition, char *expression1, char *expression2);
void		ft_copy_values(t_stack *stack_a, int copy[], int i);
void		ft_sort_copy(int copy[], int size);

// libft
long int	ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		ft_putstr(char *str);

#endif

