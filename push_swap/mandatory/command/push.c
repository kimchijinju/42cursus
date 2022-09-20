/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:06 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/19 16:24:34 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

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
