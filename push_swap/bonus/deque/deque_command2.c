/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:53:02 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 08:58:51 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"

int	peek_front(t_deque *self)
{
	int	front;

	front = (self->front);
	return (self->arr[front]);
}

int	peek_back(t_deque *self)
{
	int	back;

	back = (self->back - 1 + self->max_size) % self->max_size;
	return (self->arr[back]);
}

int	peek_back_index(t_deque *self, int index)
{
	int	back;

	back = (self->back - (index + 1) + self->max_size) % self->max_size;
	return (self->arr[back]);
}

t_bool	deque_full(t_deque *self)
{
	return (self->cur_size == self->max_size);
}

t_bool	deque_empty(t_deque *self)
{
	return (self->cur_size == 0);
}
