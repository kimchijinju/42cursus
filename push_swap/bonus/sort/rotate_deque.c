/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:26 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 10:49:11 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "command.h"

static void	rotate_same_time(t_deque *a, t_deque *b, t_min_rotate_count *move)
{
	while (move->a < 0 && move->b < 0)
	{
		rrr(a, b);
		move->a++;
		move->b++;
	}
	while (move->a > 0 && move->b > 0)
	{
		rr(a, b);
		move->a--;
		move->b--;
	}
}

static void	rotate_b(t_deque *b, t_min_rotate_count *move)
{	
	while (move->b < 0)
	{
		rrb(b);
		move->b++;
	}
	while (move->b > 0)
	{
		rb(b);
		move->b--;
	}
}

static void	rotate_a(t_deque *a, t_min_rotate_count *move)
{
	while (move->a < 0)
	{
		rra(a);
		move->a++;
	}
	while (move->a > 0)
	{
		ra(a);
		move->a--;
	}
}

void	sort_from_b_to_a(t_deque *a, t_deque *b)
{
	t_min_rotate_count	move;

	while (!b->deque_empty(b))
	{
		move = get_best_location(a, b);
		rotate_same_time(a, b, &move);
		rotate_b(b, &move);
		rotate_a(a, &move);
		pa(a, b);
	}
}
