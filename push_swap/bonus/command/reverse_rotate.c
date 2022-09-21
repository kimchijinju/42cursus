/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:06 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 09:14:15 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

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
}

void	rrb(t_deque *b)
{
	reverse_rotate(b);
}

void	rrr(t_deque *a, t_deque *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
