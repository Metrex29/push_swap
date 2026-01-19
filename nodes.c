/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:15:37 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/01/19 15:12:51 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
this function calculate the length of a stack
*/
int	stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	if(!stack)
		return (0);
	while (stack)
	{
		stack = stack -> next;
		count++;
	}
	return (count);
}

/*
this function finds the last node value of a stack
*/
t_stack_node	*find_last(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}

/*
this function finds the min node value of the stack
*/
t_stack_node	*find__min(t_stack_node *stack)
{
	// this is the  value min
	long	min;
	// this is the pointer to the min
	t_stack_node *min_node;
	
	if(!stack)
		return (NULL);
	// asign value to var
	min = stack->value;
	min_node = stack;
	while(stack)
	{
		if(stack -> value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}





