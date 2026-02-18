/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:35:31 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/02/18 17:59:22 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Prototipos
t_stack_node	*ft_new_node(int value);
t_stack_node	*find_last(t_stack_node *stack);
int				check_duplicates(t_stack_node *stack, int n);
void			add_node_back(t_stack_node **stack, t_stack_node *new_node);
void			init_stack_a(t_stack_node **a, char **argv);
void			ft_index_node(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);

// movements---------------------------------------------------------
//swap:
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);

//rotate
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);

//rrotate
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//push
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

//quick sort
void			sort_three(t_stack_node **stack);
void			sort_four(t_stack_node **a, t_stack_node **b);
void			sort_five(t_stack_node **a, t_stack_node **b);

// utils
int				get_range(int len);
t_stack_node	*find_max(t_stack_node *stack);
int				get_pos(t_stack_node *stack, t_stack_node *objetive);
long			ft_atoi(const char *str);

//ksort
void			push_to_b(t_stack_node **a, t_stack_node **b, int range);
void			push_to_a(t_stack_node **a, t_stack_node **b);

#endif