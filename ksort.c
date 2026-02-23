/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:45:21 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/02/18 21:11:37 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack_node **a, t_stack_node **b, int range)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(b, a);
			i++;
		}
		else if ((*a)->index <= (range + i))
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	push_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max_node;
	int				size;
	int				pos;

	while (*b)
	{
		size = stack_len(*b);
		max_node = find_max(*b);
		pos = get_pos(*b, max_node);
		if (pos <= size / 2)
		{
			while (*b != max_node)
				rb(b);
		}
		else
		{
			while (*b != max_node)
				rrb(b);
		}
		pa(a, b);
	}
}
