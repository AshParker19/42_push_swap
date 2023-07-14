/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:11:31 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/14 21:20:09 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_free_everything(t_store *store, char **ops_store)
{
	int	i;

	i = -1;
	while (ops_store[++i])
		free (ops_store[i]);
	free (ops_store);
	store->stack_a = ft_free_stack(store->stack_a);
	store->stack_b = ft_free_stack(store->stack_b);
}

int    ft_validate_operation(char *op, char **ops_store)
{
	int	i;

	i = -1;
	while (ops_store[++i])
	{
		if (!ft_strcmp(ops_store[i], op))
			break ;
		if (!ops_store[i + 1])
			return (0);
	}
	return (1);
}

char	**ft_initialize_ops(void)
{
	char	*ops;
	char	**ops_store;
	
	ops = "sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n";
	return (ops_store = ft_split(ops, NULL, 0, ' '));
}

void	ft_do_op(t_store *store, char *op)
{
	if (!ft_strcmp("sa\n", op))
		b_sa_sb(store->stack_a);
	else if (!ft_strcmp("sb\n", op))	
		b_sa_sb(store->stack_b);
	else if (!ft_strcmp("ss\n", op))
		b_ss(store);
	else if (!ft_strcmp("pa\n", op))
		b_pa(store);
	else if (!ft_strcmp("pb\n", op))
		b_pb(store);
	else if (!ft_strcmp("ra\n", op))
		b_ra(store);
	else if (!ft_strcmp("rb\n", op))
		b_rb(store);
	else if (!ft_strcmp("rr\n", op))
		b_rr(store);
	else if (!ft_strcmp("rra\n", op))
		b_rra(store);
	else if (!ft_strcmp("rrb\n", op))
		b_rrb(store);
	else if (!ft_strcmp("rrr\n", op))
		b_rrr(store);								
}

int	ft_result(t_stack *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	if (stack_a->value > stack_a->next->value)
		return (0);
	return (ft_result(stack_a->next));	
}

void	ft_conclusion(t_store *store, char **ops_store)
{
	if (store->stack_b)
		ft_putstr_fd("KO\n", 1);
	else if (!ft_result(store->stack_a))
		ft_putstr_fd("KO\n", 1);
	else if (ft_result(store->stack_a))
		ft_putstr_fd("OK\n", 1);	
	ft_free_everything(store, ops_store);
}

void    ft_read_commands(t_store *store)
{
	char *op;
	char **ops_store;
	
	ops_store = ft_initialize_ops();
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break;
		if (!ft_validate_operation(op, ops_store))
		{
			ft_free_everything(store, ops_store);
			ft_putstr_fd("Error\n", 2);
			exit (INVALID_OPERATION);
		}
		else
			ft_do_op(store, op);
		free (op);	
	}
	ft_conclusion(store, ops_store);
}

int	ft_valid(int ac, char *av[])
{
	if (ac == 1 || (ac == 2 && ft_numeric(av[1])
			&& (ft_atoi(av[1]) > INT_MIN
				&& ft_atoi(av[1]) < INT_MAX) && *av[1]))
		return (1);
	return (0);
}

void	ft_make_stack(int ac, char *av[], int i)
{
	t_store store;
	
	ft_initialize(&store);
	while (++i < ac)
		store.stack_a = ft_addback(&store, ft_atoi(av[i]));
	ft_read_commands(&store);
	store.stack_a = ft_free_stack(store.stack_a);
}

int main(int ac, char *av[]) // pars here
{
	if (ft_valid(ac, av))
		exit (SORTED_ALREADY);
	if (ft_checker(ac, av))	
		ft_make_stack(ac, av, 0);
}

// create a stack ✓
// after that use get_next_line in a loop to read the commands ✓
// store the commands in the matrix ✓
// call the corresponding operations ✓
// check if the linked list is sorted ✓
// do parsing ✓
// find the leack ✓