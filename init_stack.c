/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:22:08 by raulp             #+#    #+#             */
/*   Updated: 2026/02/03 13:02:16 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack_a(t_stack_node **a, char **argv)
{
	long n;
	int i;

	i = 0;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n == 2147483648L || check_duplicates(*a, (int)n))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		add_node_back(a, ft_new_node((int)n));
		i++;
	}
}