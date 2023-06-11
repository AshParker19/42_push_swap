/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_fts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:13:54 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/11 21:44:35 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(int ac, char *av[])
{
	t_stack 	*stack_a;
	t_stack		*stack_b;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (++i < ac)
		stack_a = ft_addback(stack_a, ft_atoi(av[i]));
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	
	// sa_sb(stack_a);
	// sa_sb(stack_b);
	// ss(stack_a, stack_b);
	
	// ra_rb(stack_a);
	// ra_rb(stack_b);
	// rr(stack_a, stack_b);
	// rra_rrb(stack_a);
	// rra_rrb(stack_b);
	// rrr(stack_a, stack_b);
	
	ft_print_list(stack_a, stack_b);
	stack_a = ft_free_stack(stack_a);
	stack_b = ft_free_stack(stack_b);
}

void	ft_print_list(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current_a = stack_a;
	t_stack *current_b = stack_b;
	
	printf(YELLOW"╔═══════════════╗\n"RESET);
	printf(PURPLE"        A        \n"RESET);
	if (!current_a)
		printf(RED"     EMPTY!!\n" RESET);
	else if (!current_a->next && !current_a->prev)
		printf(RED"    ONLY HEAD\n"RESET);	
	while (current_a)
	{
		printf(GREEN" CURRENT_A NUM %d\n"RESET, current_a->value);
		if (!current_a->prev)
			printf(CYAN" PREV - NULL\n"RESET);
		else 
			printf (CYAN" PREV VALUE - %d\n"RESET, current_a->prev->value);	
		if (!current_a->next)	
			printf(CYAN" NEXT - NULL\n"RESET);
		else
			printf (CYAN" NEXT VALUE - %d\n"RESET, current_a->next->value);
		if (current_a->next)
			printf(YELLOW"=================\n"RESET);	
		current_a = current_a->next;
	}
	printf(YELLOW"╚═══════════════╝\n"RESET);
	
	printf(YELLOW"╔═══════════════╗\n"RESET);
	printf(PURPLE"        B        \n"RESET);
	if (!current_b)
		printf(RED"     EMPTY!!\n"RESET);
	else if (!current_b->next && ! current_b->prev)
		printf(RED"    ONLY HEAD\n"RESET);	
	while (current_b)
	{
		printf(GREEN" CURRENT_B NUM %d\n"RESET, current_b->value);
		if (!current_b->prev)
			printf(CYAN" PREV - NULL\n"RESET);
		else 
			printf (CYAN" PREV VALUE - %d\n"RESET, current_b->prev->value);	
		if (!current_b->next)	
			printf(CYAN" NEXT - NULL\n"RESET);
		else
			printf (CYAN" NEXT VALUE - %d\n"RESET, current_b->next->value);
		if (current_b->next)	
			printf(YELLOW"=================\n"RESET);	
		current_b = current_b->next;
	}
	printf(YELLOW"╚═══════════════╝\n"RESET);
}

t_stack	*ft_addback(t_stack *head, int new_value)
{
	t_stack	*new;
	t_stack	*current;

	new = ft_calloc(1, sizeof(t_stack));
	new->value = new_value;
	current = head;
	if (!head)
		return (new);
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
		return (head);
	}	
}

t_stack	*ft_free_stack(t_stack *st)
{
	if (st)
	{
		ft_free_stack(st->next);
		free (st);
	}
	return (NULL);
}
