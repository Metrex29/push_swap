/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:22:08 by raulp             #+#    #+#             */
/*   Updated: 2026/02/18 18:28:24 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void if_error(t_stack_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void init_stack_a(t_stack_node **a, char **argv)
{
	long n;
	int i;
	t_stack_node *new_node;

	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			if_error(a);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN || check_duplicates(*a, (int)n))
			if_error(a);
		new_node = ft_new_node((int)n);
		if (!new_node)
			if_error(a);
		add_node_back(a, new_node);
		i++;
	}
}
