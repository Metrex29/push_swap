/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:02:04 by raulp             #+#    #+#             */
/*   Updated: 2026/02/10 12:51:42 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node *node_temp;

	if (!src || !*src)
		return ;
	node_temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;

	node_temp->next = *dest;

	if (*dest)						  // Si la pila destino NO estaba vacía...
		(*dest)->prev = node_temp; // ...el antiguo primero ahora mira atrás al nuevo jefe

	*dest = node_temp;
	node_temp->prev = NULL;
}

void pa(t_stack_node **a, t_stack_node **b)
{
    ft_push(a, b);
    write(1, "pa\n", 3);
}

void pb(t_stack_node **b, t_stack_node **a)
{
    ft_push(b, a);
    write(1, "pb\n", 3);
}