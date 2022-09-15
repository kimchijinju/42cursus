/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:06 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/13 10:19:36 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "command.h"
#include <unistd.h>

void	swap(t_deque *deque)
{
	int	up;
	int	down;

	if (deque->cur_size < 2)
		return ;
	up = deque->peek_back(deque);
	deque->pop_back(deque);
	down = deque->peek_back(deque);
	deque->pop_back(deque);
	deque->push_back(deque, up);
	deque->push_back(deque, down);
}

void	sa(t_deque *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	push(t_deque *a, t_deque *b)
{
	int	a_top;
	
	if (a->cur_size < 1)
		return ;
	a_top = a->peek_back(a);
	a->pop_back(a);
	b->push_back(b, a_top);
}

void	pa(t_deque *a, t_deque *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_deque *a, t_deque *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	rotate(t_deque *deque)
{
	int	top;

	if (deque->deque_empty(deque))
		return ;
	top = deque->peek_back(deque);
	deque->pop_back(deque);
	deque->push_front(deque, top);
}

void	ra(t_deque *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_deque *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_deque *a, t_deque *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_deque *deque)
{
	int	bottom;

	if (deque->deque_empty(deque))
		return ;
	bottom = deque->peek_front(deque);
	deque->pop_front(deque);
	deque->push_back(deque, bottom);
}

void	rra(t_deque *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
