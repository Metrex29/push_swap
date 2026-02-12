/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:19:58 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/02/12 15:52:41 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// case 1: 1,0,2
// case 2: 2,1,0
// case 3: 2,0,1
// case 4: 1,2,0
// case 5: 0,2,1
void sort_three(t_stack_node **stack)
{
	int first;
	int second;
	int third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && third < first)
		rra(stack);
	else if (first < second && second > third)
	{
		rra(stack);
		sa(stack);
	}
}

void sort_four(t_stack_node **a, t_stack_node **b)
{
	if ((*a)->next->index == 0)
		sa(a);
	else if ((*a)->next->next->index == 0)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->index == 0)
		rra(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void sort_five(t_stack_node **a, t_stack_node **b)
{
	if ((*a)->next->index == 0)
		sa(a);
	else if ((*a)->next->next->index == 0)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->index == 0)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->next->index == 0)
		rra(a);
	pb(b, a);
	sort_four(a, b);
	pa(a, b);
}


