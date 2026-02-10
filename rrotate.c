/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:51:27 by raulp             #+#    #+#             */
/*   Updated: 2026/02/10 16:36:47 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rrotate(t_stack_node **stack)
{

	t_stack_node *a;
	t_stack_node *last_node;
	t_stack_node *pre_last;

	if (!stack || !*stack || !(*stack)->next)
		return;
		
	last_node = find_last(*stack);
	pre_last = last_node->prev;
	pre_last->next = NULL;
	
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
	last_node->prev = NULL;
}

void rra(t_stack_node **a)
{
	ft_rrotate(a);
	write(1,"rra\n",4);
}

void rrb(t_stack_node **b)
{
	ft_rrotate(b);
	write(1,"rrb\n",4);
}

void rrr(t_stack_node **a,t_stack_node **b)
{
	ft_rrotate(a);
	ft_rrotate(b);
	write(1,"rrr\n",4);
}