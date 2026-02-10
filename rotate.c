/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:01:16 by raulp             #+#    #+#             */
/*   Updated: 2026/02/10 16:37:30 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_stack_node **stack)
{
	t_stack_node *a;
	t_stack_node *b;

	if(!stack || !*stack || !(*stack)->next)
		return;
	a = *stack;
	b = (*stack)->next;

	*stack = b;
	b->prev = NULL;
	a->next = NULL;
	add_node_back(stack, a);
}
void ra(t_stack_node **a)
{
	ft_rotate(a);
	write(1,"ra\n", 3);
}
void rb(t_stack_node **b)
{
	ft_rotate(b);
	write(1,"rb\n", 3);
}