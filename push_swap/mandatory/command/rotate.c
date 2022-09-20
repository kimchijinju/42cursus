/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:06 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/19 16:22:01 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

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
