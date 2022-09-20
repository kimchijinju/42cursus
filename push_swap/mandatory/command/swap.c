/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:06 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/19 16:17:18 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

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
