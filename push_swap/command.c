/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:06 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/05 21:27:01 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	sa(t_deque *a)
{
	int	up;
	int	down;

	if (a->cur_size < 2)
		return ;
	up = a->peek_back(a);
	a->pop_back(a);
	down = a->peek_back(a);
	a->pop_back(a);
	a->push_back(a, up);
	a->push_back(a, down);
}

void	sb(t_deque *b)
{
	int	up;
	int	down;

	if (b->cur_size < 2)
		return ;
	up = b->peek_back(b);
	b->pop_back(b);
	down = b->peek_back(b);
	b->pop_back(b);
	b->push_back(b, up);
	b->push_back(b, down);
}

void	ss(t_deque *a, t_deque *b)
{
	sa(a);
	sb(b);
}

void	pa(t_deque *a, t_deque *b)
{
	int	a_top;
	
	if (a->cur_size < 1)
		return ;
	a_top = a->peek_back(a);
	a->pop_back(a);
	b->push_back(b, a_top);
}

void	pb(t_deque *a, t_deque *b)
{
	int	b_top;
	
	if (b->cur_size < 1)
		return ;
	b_top = b->peek_back(b);
	b->pop_back(b);
	a->push_back(a, b_top);

}

void	ra(t_deque *a)
{

}

void	rb(t_deque *a)
{

}

void	rr(t_deque *a, t_deque *b)
{

}

void	rra(t_deque *a, t_deque *b)
{

}

void	rrb(t_deque *a, t_deque *b)
{

}

void	rrr(t_deque *a, t_deque *b)
{

}
