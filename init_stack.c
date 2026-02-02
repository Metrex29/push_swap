/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:22:08 by raulp             #+#    #+#             */
/*   Updated: 2026/02/02 18:48:41 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int check_duplicates(t_stack_node *stack, int n)
{
	if(!stack)
		return 0;
	while (stack)
	{
		if(stack ->value == n)
			return 1;
		stack = stack -> next;
	}
	return 0;
}
