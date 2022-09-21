/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:06 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 09:14:27 by hanbkim          ###   ########.fr       */
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
}

void	rb(t_deque *b)
{
	rotate(b);
}

void	rr(t_deque *a, t_deque *b)
{
	rotate(a);
	rotate(b);
}
