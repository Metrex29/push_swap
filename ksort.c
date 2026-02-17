/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:45:21 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/02/17 11:21:56 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// primer if, si el primer numero del stack a es menor que el contador, pasa a pb,
// eel segundo si es menor que la suma del rango y el i pasa como ultima posicion,
//, si no esta en el rango salta al final del stack esperando a que pase a la ultima posicion, hasya que pueda segir con el bucle

void push_to_b(t_stack_node **a, t_stack_node **b, int range)
{
	int i;
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

