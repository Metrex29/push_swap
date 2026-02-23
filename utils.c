/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:00:11 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/02/23 14:02:10 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * ft_index_node - assign a rank index to each node based on values in the list
 *
 * @stack: pointer to the head of a singly linked list of t_stack_node.
 *
 * For each node in the list this function counts how many nodes contain a
 * strictly smaller `value` and stores that count in the node's `index` field.
 * The smallest value(s) receive index 0; larger values receive an index equal
 * to the number of strictly smaller elements in the list.
 *
 * Return: void
 *
 * Complexity: O(n^2) time (double traversal), O(1) extra space.
 *
 * Side effects:
 *  - Overwrites the `index` member of every node in the list.
 *
 * Preconditions / assumptions:
 *  - Each node in the list has accessible `value`, `index`, and `next` members.
 *  - `stack` is either NULL (no-op) or a properly terminated singly linked list.
 *
 * Notes / cautions:
 *  - The current implementation must ensure the counter used for counting is
 *    reinitialized for each node (i.e., set to 0 inside the outer loop);
 *    otherwise the computed indices will be incorrect.
 *  - Duplicate values will result in identical indices for those nodes.
 */
void	ft_index_node(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*cmp;
	int				i;

	i = 0;
	current = stack;
	while (current)
	{
		i = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < current->value)
				i++;
			cmp = cmp->next;
		}
		current->index = i;
		current = current->next;
	}
}

int	get_range(int len)
{
	if (len <= 100)
		return (16);
	return (32);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	int					max;
	t_stack_node		*max_node;

	if (!stack)
		return (NULL);
	max = stack->index;
	max_node = stack;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	get_pos(t_stack_node *stack, t_stack_node *objetive)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == objetive)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		value;
	long	result;

	value = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			value *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * value > INT_MAX || result * value < INT_MIN)
			return (2147483648L);
		i++;
	}
	return (result * value);
}
