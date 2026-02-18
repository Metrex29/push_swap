/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:58:15 by raulp             #+#    #+#             */
/*   Updated: 2026/02/18 17:43:53 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack_node **stack)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	a = *stack;
	b = a->next;
	c = b->next;
	b->next = a;
	b->prev = NULL;
	a->next = c;
	a->prev = b;
	if (c)
		c->prev = a;
	*stack = b;
}

void	sa(t_stack_node **a)
{
	ft_swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	ft_swap(b);
	write (1, "sb\n", 3);
}
