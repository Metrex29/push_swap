/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:01:16 by raulp             #+#    #+#             */
/*   Updated: 2026/02/17 15:18:26 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = find_last(*stack);
	last->next = first;
	first->prev = last;
	first->next = NULL;
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