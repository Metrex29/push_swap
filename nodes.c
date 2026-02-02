/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:15:37 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/02/02 18:23:54 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * ft_new_node - Create and initialize a new stack node
 * @value: Integer value to store in the node
 *
 * Allocates and returns a pointer to a newly-created t_stack_node containing
 * the given value. All pointer/linking fields are initialized to NULL and any
 * auxiliary fields are set to sensible defaults (e.g., zeroed). Returns NULL
 * if memory allocation fails.
 *
 * The caller takes ownership of the returned node and is responsible for
 * freeing it. Time complexity: O(1). No global state is modified by this call.
 */
t_stack_node *ft_new_node(int value)
{
	t_stack_node *node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*
this function calculate the length of a stack
*/
int stack_len(t_stack_node *stack)
{
	int count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/*
this function finds the last node value of a stack
*/
t_stack_node *find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*
this function finds the min node value of the stack
*/
t_stack_node *find_min(t_stack_node *stack)
{
	// this is the  value min
	long min;
	// this is the pointer to the min
	t_stack_node *min_node;

	if (!stack)
		return (NULL);
	// asign value to var
	min = stack->value;
	min_node = stack;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void add_node_back(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node *last_node;

	if (!stack || !new_node)
		return;
		
	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	// Buscamos el nodo que está actualmente al final
	last_node = find_last(*stack);

	// El que era el último ahora apunta al nuevo como su siguiente
	last_node->next = new_node;

	// El nuevo apunta al que era el último como su anterior
	new_node->prev = last_node;
}

