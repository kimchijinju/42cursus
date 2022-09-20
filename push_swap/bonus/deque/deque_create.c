/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:53:02 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 08:53:21 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"

static void	function_constructor(t_deque *new)
{
	new->push_front = push_front;
	new->push_back = push_back;
	new->pop_front = pop_front;
	new->pop_back = pop_back;
	new->peek_front = peek_front;
	new->peek_back = peek_back;
	new->deque_empty = deque_empty;
	new->deque_full = deque_full;
	new->peek_back_index = peek_back_index;
	new->get_max_value = get_max_value;
	new->get_max_value_index = get_max_value_index;
	new->get_min_value = get_min_value;
	new->get_min_value_index = get_min_value_index;
}

t_deque	*create_deque(int n)
{
	t_deque	*new;

	new = malloc(sizeof(t_deque));
	if (!new)
		return (NULL);
	new->cur_size = 0;
	new->max_size = n;
	new->back = 0;
	new->front = 0;
	new->arr = malloc(sizeof(int) * n);
	if (!new->arr)
	{
		free(new);
		return (NULL);
	}
	function_constructor(new);
	return (new);
}
