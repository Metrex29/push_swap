/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:38:35 by cpicon-m          #+#    #+#             */
/*   Updated: 2026/02/18 19:18:35 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* split.c                                            :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/02/18 18:30:00 by cpicon-m          #+#    #+#             */
/* Updated: 2026/02/18 18:35:00 by cpicon-m         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*put_word(const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **resul, int j)
{
	while (j > 0)
	{
		j--;
		free(resul[j]);
	}
	free(resul);
}

static int	insert_words(char **resul, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			resul[j] = put_word(&s[i], c);
			if (!resul[j])
			{
				free_split(resul, j);
				return (0);
			}
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	resul[j] = (NULL);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**resul;
	int		words;

	if (!s)
		return (NULL);
	words = count_word(s, c);
	resul = malloc((words + 1) * sizeof(char *));
	if (!resul)
		return (NULL);
	if (!insert_words(resul, s, c))
		return (NULL);
	return (resul);
}
