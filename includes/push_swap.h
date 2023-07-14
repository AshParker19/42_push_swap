/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:56:22 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 15:55:14 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

/**********FLAGS**********/
// errors
# define SORTED_ALREADY  0
# define NOT_NUMERIC 	 1
# define INVALID_INT 	 2

// stacks flags
# define NEUTRAL		 3
# define STACK_A 		 4
# define STACK_B 		 5

// directions
# define UP				 6
# define DOWN			 7

// range
# define BIGGEST		 8
# define SND_BIGGEST	 9
/*************************/

// linked list structure
typedef struct s_stack
{
	int				value;
	int				index;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// structure with all the data
typedef struct s_store
{
	int		count_a;
	int		count_b;
	int		chunk_size;
	int		chunk_num;
	int		biggest;
	int		snd_biggest;
	int		smallest;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tail_a;
	t_stack	*tail_b;
}				t_store;

/**************************** ALMIGHTY PUSH SWAP ****************************/
// push to b
void		ft_push_b_main(t_store *store);
void		ft_push_pairs(t_store *store, int flag_down,
				int flag_up, int count);
void		ft_push_the_rest(t_store *store, int count, int chunk_index);
int			ft_manage_details(t_store *store, int bottom_flag,
				int top_flag, int *dir);
void		ft_manage_rr(t_store *store, int cost, int dir);
void		ft_manage_top_a(t_store *store, int bottom_flag);
void		ft_manage_rra(t_store *store, int cost, int dir, int bottom_flag);
void		ft_manage_rra2(t_store *store, int cost, int dir, int mean);
// sort the remainder
void		ft_sort_the_remainder(t_store *store);
// push to a
void		ft_push_to_a(t_store *store, int count, int first, int dir);
void		ft_manage_snd_biggest(t_store *store, int *count, int to_push);
void		ft_rollback(t_store *store, int ra_count);
int			ft_manage_sb(t_store *store);
/****************************************************************************/

// linked lists 
void		ft_create_stack(int ac, char *av[], int i, int j);
void		ft_initialize_store(t_store *store, int count_a);
t_stack		*ft_addback(t_store *store, int new_value);
void		ft_print_list(t_store *store);
t_stack		*ft_free_stack_a(t_stack *stack_a);

// operations 
void		sa_sb(t_stack *stack, int flag);
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
void		ft_sort_main(t_store *store, int copy[]);
void		ft_sort_3(t_store *store);
void		ft_sort_4_5(t_store *store, int save);
void		ft_sort_less10(t_store *store, int flag);
void		ft_almighty_ps(t_store *store, int copy[]);

// sorting utils
void		ft_find_the_smallest(t_store *store, t_stack *stack_a, int i);
void		ft_index(t_stack *stack_a, int i);
void		ft_marker(t_store *store, t_stack *stack_a,
				int copy[], int chunk_index);
int			ft_find_position(t_stack *stack, int to_find);
int			ft_find_the_cost(int index, int count, int *dir);
int			ft_find_the_cost2(t_store *store, int *dir, int *to_push);
int			ft_from_start(t_stack *stack_a, int find_flag);
int			ft_from_end(t_stack *tail_a, int find_flag);
int			ft_get_dir_a(t_store *store, int flag1, int flag2, int *dir);
int			ft_get_dir_b(t_store *store, int value, int *dir);
void		ft_rotate_stack(t_store *store, int cost, int dir, int stack_flag);
int			ft_count_flags(t_stack *stack_a, int find_flag);
int			ft_closer(t_store *store, int flag, int *dir);
void		ft_1st_2nd(t_store *store, t_stack *stack_b, int i);
int			ft_chunk_sum(t_stack *stack_a, int find_flag);
void		ft_rotate_up(t_store *store, int smallest_index, int i);

// parsing
void		ft_start_from_quotes(char *in_quotes);
int			ft_check_splitted(char **splitted, int count);
int			ft_checker(int ac, char *av[]);
int			ft_checker2(int ac, char *av[], int i);
int			ft_numeric(char *str);
int			ft_check_if_sorted(int ac, char *av[], int i);
int			ft_check_if_empty(char *in_quotes);

// utils
void		ft_copy_values(t_stack *stack_a, int copy[], int i);
void		ft_sort_copy(int copy[], int size);
int			ft_find_pos_array(int copy[], int size, int to_find, int i);
void		ft_free_splitted(char *splitted[]);

// libft
long int	ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_putstr_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
char		**ft_split(char *str, char *arr[], int count, char c);

#endif
