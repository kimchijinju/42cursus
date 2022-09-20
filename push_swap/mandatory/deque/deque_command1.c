/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:53:02 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 08:56:58 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

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
