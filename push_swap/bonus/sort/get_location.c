/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:26 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 11:37:32 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	judge_forward_reverse(t_deque *deque, int count)
{
	if (count > deque->cur_size / 2)
		count = (deque->cur_size - count) * -1;
	return (count);
}

static int	get_a_rotate_count(t_deque *a, int b_value)
{
	int	count;

	if (b_value > a->get_max_value(a))
		count = get_max_value_index(a);
	else
		count = get_min_value_index(a, b_value);
	count = judge_forward_reverse(a, count);
	return (count);
}

t_min_rotate_count	get_best_location(t_deque *a, t_deque *b)
{
	int					count;
	int					b_value;
	int					a_rotate_count;
	int					b_rotate_count;
	t_min_rotate_count	min;

	count = 0;
	min.a = a->cur_size;
	min.b = b->cur_size;
	while (count < b->cur_size)
	{
		b_value = b->peek_back_index(b, count);
		a_rotate_count = get_a_rotate_count(a, b_value);
		b_rotate_count = judge_forward_reverse(b, count);
		if (ft_abs(a_rotate_count) + ft_abs(b_rotate_count) < ft_abs(min.a) + ft_abs(min.b))
		{
			min.a = a_rotate_count;
			min.b = b_rotate_count;
		}
		count++;
	}
	return (min);
}
