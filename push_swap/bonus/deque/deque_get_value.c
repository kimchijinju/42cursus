/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_get_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:53:02 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 08:54:22 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	get_min_value(t_deque *self)
{
	int	i;
	int	min;
	int	size;
	int	back;

	i = 0;
	min = self->peek_back(self);
	size = self->cur_size;
	while (size)
	{
		back = (self->back - 1 - i + self->max_size) % self->max_size;
		if (min > self->arr[back])
			min = self->arr[back];
		i++;
		size--;
	}
	return (min);
}

int	get_min_value_index(t_deque *self, int target)
{
	int	i;
	int	min;
	int	size;
	int	min_index;
	int	back;

	i = 0;
	min_index = i;
	min = 2147483647;
	size = self->cur_size;
	while (size)
	{
		back = (self->back - 1 - i + self->max_size) % self->max_size;
		if (min > self->arr[back] && self->arr[back] > target)
		{
			min_index = i;
			min = self->arr[back];
		}
		i++;
		size--;
	}
	return (min_index);
}

int	get_max_value(t_deque *self)
{
	int	i;
	int	back;
	int	max;
	int	max_index;

	i = 0;
	max_index = i;
	max = self->peek_back(self);
	while (i < self->cur_size)
	{
		back = (self->back - 1 - i + self->max_size) % self->max_size;
		if (max < self->arr[back])
		{
			max_index = i;
			max = self->arr[back];
		}
		i++;
	}
	return (max);
}

int	get_max_value_index(t_deque *self)
{
	int	i;
	int	back;
	int	max;
	int	max_index;

	i = 0;
	max_index = i;
	max = self->peek_back(self);
	while (i < self->cur_size)
	{
		back = (self->back - 1 - i + self->max_size) % self->max_size;
		if (max < self->arr[back])
		{
			max_index = i;
			max = self->arr[back];
		}
		i++;
	}
	return (max_index + 1);
}
