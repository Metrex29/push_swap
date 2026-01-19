/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:35:31 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/01/15 15:45:47 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					value; // El número a ordenar
	int					index; // Su posición ideal (lo usaremos luego)
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Prototipos
t_stack_node	*ft_new_node(int value);

#endif