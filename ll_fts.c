/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_fts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:13:54 by anshovah          #+#    #+#             */
/*   Updated: 2023/06/10 14:58:16 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(int ac, char *av[])
{
	t_stack 	*s_a;
	t_stack		*s_b;
	int			i;

	s_a = NULL;
	s_b = NULL;
	i = 0;
	while (++i < ac)
		s_a = ft_addback(s_a, ft_atoi(av[i]));
	pb(&s_a, &s_b);
	pb(&s_a, &s_b);
	pb(&s_a, &s_b);
	// pb(&s_a, &s_b);
	// pa(&s_a, &s_b);
	// pa(&s_a, &s_b);
	// pa(&s_a, &s_b);
	
	// sa_sb(s_a);
	// sa_sb(s_b);
	// ss(s_a, s_b);
	// ra_rb(s_a);
	// ra_rb(s_b);
	// rr(s_a, s_b);
	// rra_rrb(s_a);
	// rra_rrb(s_b);
	// rrr(s_a, s_b);
	ft_print_list(s_a, s_b);
	// s_a = ft_free_stack(s_a);
	// s_b = ft_free_stack(s_b);	
}

void	ft_print_list(t_stack *s1, t_stack *s2)
{
	t_stack *current_a = s1;
	t_stack *current_b = s2;
	
	printf(YELLOW"╔═══════════════╗\n"RESET);
	printf(PURPLE"        A        \n"RESET);
	if (!current_a)
		printf(RED"     EMPTY!!\n" RESET);
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

t_stack	*ft_addfront(t_stack *head, int new_value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	new->value = new_value;
	if (!head)
		return (new);
	else
	{
		new->next = head;
		head->prev = new;
		return (new);
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
