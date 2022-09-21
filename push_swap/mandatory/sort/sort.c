/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:26 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/21 14:34:50 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "push_swap.h"
#include "command.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	clean_up(t_deque *a)
{	
	int	a_min_index;
	int	a_min;

	a_min_index = a->get_min_value_index(a, a->peek_back(a));
	a_min = a->get_min_value(a);
	if (a_min_index > a->cur_size / 2)
	{
		while (a->peek_back(a) != a_min)
			rra(a);
	}
	else
	{
		while (a->peek_back(a) != a_min)
			ra(a);
	}
}

static void	sort_two_elem(t_deque *a)
{
	if (a->peek_back_index(a, 0) > a->peek_back_index(a, 1))
		sa(a);
}

void	sort_three_elem(t_deque *a)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = a->peek_back_index(a, 0);
	v2 = a->peek_back_index(a, 1);
	v3 = a->peek_back_index(a, 2);
	if ((v1 > v2) && (v2 > v3) && (v1 > v3))
	{
		sa(a);
		rra(a);
	}
	else if (v1 > v2 && v2 < v3 && v1 < v3)
		sa(a);
	else if (v1 > v2 && v2 < v3 && v1 > v3)
		ra(a);
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		sa(a);
		ra(a);
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		rra(a);
}

void	sort_deque(t_deque *a, t_deque *b)
{
	if (a->cur_size == 2)
	{
		sort_two_elem(a);
		return ;
	}
	if (a->cur_size == 3)
	{
		sort_three_elem(a);
		return ;
	}
	partitioning(a, b);
	sort_from_b_to_a(a, b);
	clean_up(a);
}
