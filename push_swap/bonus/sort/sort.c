/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:26 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 11:35:51 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sort_deque(t_deque *a, t_deque *b)
{
	partitioning(a, b);
	sort_from_b_to_a(a, b);
	clean_up(a);
}
