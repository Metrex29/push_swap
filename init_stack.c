/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:22:08 by raulp             #+#    #+#             */
/*   Updated: 2026/02/23 13:41:01 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	if_error(t_stack_node **stack, char **argv)
{
	free_args(argv);
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

static void	process_args(t_stack_node **a, char **args_split)
{
	long			n;
	int				j;
	t_stack_node	*new_node;

	j = 0;
	while (args_split[j])
	{
		if (!is_number(args_split[j]))
			if_error(a, args_split);
		n = ft_atoi(args_split[j]);
		if (n > INT_MAX || n < INT_MIN || check_duplicates(*a, (int)n))
			if_error(a, args_split);
		new_node = ft_new_node((int)n);
		if (!new_node)
			if_error(a, args_split);
		add_node_back(a, new_node);
		j++;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	char	**args_split;

	i = 0;
	while (argv[i])
	{
		args_split = ft_split(argv[i], ' ');
		if (!args_split)
			if_error(a, NULL);
		process_args(a, args_split);
		free_args(args_split);
		i++;
	}
}
