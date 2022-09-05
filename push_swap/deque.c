/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:53:02 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/05 21:25:00 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdlib.h>

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

void	push_front(t_deque *self, int val)
{
	if (self->deque_full(self))
		return ;
	self->front = (self->front - 1 + self->max_size) % self->max_size;
	self->arr[self->front] = val;
	self->cur_size++;
}

void	push_back(t_deque *self, int val)
{
	if (self->deque_full(self))
		return ;
	self->arr[self->back] = val;
	self->back = (self->back + 1) % self->max_size;
	self->cur_size++;
}

void	pop_front(t_deque *self)
{
	if (self->deque_empty(self))
		return ;
	self->front = (self->front + 1) % self->max_size;
	self->cur_size--;
}

void	pop_back(t_deque *self)
{
	if (self->deque_empty(self))
		return ;
	self->back = (self->back - 1 + self->max_size) % self->max_size;
	self->cur_size--;
}

int	peek_front(t_deque *self)
{
	int front;

	front = (self->front);
	return (self->arr[front]);
}

int	peek_back(t_deque *self)
{
	int back;

	back = (self->back - 1 + self->max_size) % self->max_size;
	return (self->arr[back]);
}

t_bool deque_full(t_deque *self)
{
	return (self->cur_size == self->max_size);
}

t_bool deque_empty(t_deque *self)
{
	return (self->cur_size == 0);
}
