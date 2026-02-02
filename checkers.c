/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:44 by raulp             #+#    #+#             */
/*   Updated: 2026/02/02 19:12:01 by raulp            ###   ########.fr       */
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