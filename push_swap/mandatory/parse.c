/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:16:57 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 11:16:34 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_deque(t_deque *deque)
{
	free(deque->arr);
	free(deque);
	return (NULL);
}

char	**parse_input(int argc, char **argv)
{
	int		i;
	char	*join;
	char	*temp;
	char	**split;

	join = ft_strdup("");
	if (join == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin_with_space(join, argv[i]);
		if (temp == NULL)
		{
			free(join);
			return (NULL);
		}
		free(join);
		join = temp;
		i++;
	}
	split = ft_split(join, ' ');
	free(join);
	return (split);
}

static t_bool	init_element(t_deque *deque, size_t arr_size, char **input)
{
	size_t	i;

	i = 0;
	while (i < arr_size)
	{
		if (wrong_input(input[i]))
			return (FALSE);
		deque->push_front(deque, ft_atoi(input[i]));
		i++;
	}
	return (TRUE);
}

t_deque	*create_deque_and_fill_array(char **input, size_t element_size)
{
	t_deque	*deque;

	deque = create_deque(element_size);
	if (deque == NULL)
		return (NULL);
	if (init_element(deque, element_size, input) == FALSE)
		return (free_deque(deque));
	if (duplicate_input(deque->arr, element_size))
		return (free_deque(deque));
	return (deque);
}

t_bool	init_deque(t_deque **a, t_deque **b, char **input)
{
	size_t	element_size;

	element_size = 0;
	while (input[element_size] != NULL)
		element_size++;
	*a = create_deque_and_fill_array(input, element_size);
	free_split(input, element_size);
	if (*a == NULL)
		return (FALSE);
	*b = create_deque(element_size);
	if (*b == NULL)
	{
		free_deque(*a);
		return (FALSE);
	}
	return (TRUE);
}
