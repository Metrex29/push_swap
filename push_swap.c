/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:24:50 by raulp             #+#    #+#             */
/*   Updated: 2026/02/17 15:13:02 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;

	a = NULL;
	b = NULL;

	if (argc < 2)
		return 0;

	// algoritmo de agregar nodos al stack a
	init_stack_a(&a, argv + 1);
	if(is_sorted(a))
		return (0);
	ft_index_node(a);
	len = stack_len(a);
	if (len == 2)
		sa(&a);
	else if (len == 3)
		sort_three(&a);
	else if (len == 4)
		sort_four(&a,&b);
	else if (len == 5)
		sort_five(&a,&b);
	else
	{
		push_to_b(&a, &b, get_range(len));
		push_to_a(&a, &b);
	}	
	return 0;
}