/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:15:37 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/01/15 16:21:20 by cpicon-m         ###   ########.fr       */
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
int	find_last(t_stack_node *stack)
{
	if(!stack)
		return (0);
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}

