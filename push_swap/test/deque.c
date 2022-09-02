/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:53:02 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/02 22:01:32 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdlib.h>

t_deque	*create_deque(int n)
{
	t_deque	*new;

	new = malloc(sizeof(t_deque));
	new->size = 0;
	new->back = n / 2;
	new->front = n / 2 - 1;
	new->arr = malloc((sizeof(int) * n) * 2);
	new->push_front = push_front;
	new->push_back = push_back;
	new->pop_front = pop_front;
	new->pop_back = pop_back;
	new->peek_front = peek_front;
	new->peek_back = peek_back;
	new->deque_empty = deque_empty;
	return (new);
}

void	push_front(t_deque *self, int val)
{
	self->arr[FRONT--] = val;
	self->size++;
}

void	push_back(t_deque *self, int val)
{
	self->arr[BACK++] = val;
	self->size++;
}

void	pop_front(t_deque *self)
{
	if (self->deque_empty(self))
		return ;
	self->front++;
	self->size--;
}

void	pop_back(t_deque *self)
{
	if (self->deque_empty(self))
		return ;
	self->back--;
	self->size--;
}

int	peek_front(t_deque *self)
{
	return (self->arr[FRONT + 1]);
}

int	peek_back(t_deque *self)
{
	return (self->arr[BACK - 1]);
}

t_bool deque_empty(t_deque *self)
{
	return (self->size == 0);
}

#include <stdio.h>
int main()
{
	t_deque *deque = create_deque(4 * 2);

	deque->push_front(deque, 4);
	deque->push_front(deque, 3);
	deque->push_front(deque, 2);
	deque->push_front(deque, 1);
	deque->push_back(deque, 5);
	deque->push_back(deque, 6);
	deque->push_back(deque, 7);
	deque->push_back(deque, 8);
	while (!deque->deque_empty(deque))
	{
		printf("%d, %d\n", deque->peek_front(deque), deque->front + 1);
		printf("%d, %d\n", deque->peek_back(deque), deque->back - 1);
		deque->pop_front(deque);
		deque->pop_back(deque);
	}
}
