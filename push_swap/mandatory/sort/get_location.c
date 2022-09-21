/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:26 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 11:44:48 by hanbkim          ###   ########.fr       */
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

static t_bool	judge_min_rotate(int a, int b, int min_a, int min_b)
{
	return (ft_abs(b) + ft_abs(a) < ft_abs(min_a) + ft_abs(min_b));
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
		if (judge_min_rotate(a_rotate_count, b_rotate_count, min.a, min.b))
		{
			min.a = a_rotate_count;
			min.b = b_rotate_count;
		}
		count++;
	}
	return (min);
}
