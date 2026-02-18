/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:24:50 by raulp             #+#    #+#             */
/*   Updated: 2026/02/18 19:23:20 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack_node **a, t_stack_node **b, int len)
{
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
	else
	{
		push_to_b(a, b, get_range(len));
		push_to_a(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	init_stack_a(&a, argv + 1);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	ft_index_node(a);
	sort_stack(&a, &b, stack_len(a));
	free_stack(&a);
	free_stack(&b);
	return (0);
}
