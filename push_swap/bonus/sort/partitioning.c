/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:26 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 10:55:07 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "command.h"

static void	array_copy(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	get_pivot(t_deque *a, int *pivot1, int *pivot2)
{
	int	*arr;

	arr = malloc(sizeof(int) * a->max_size);
	if (!arr)
		return ;
	array_copy(arr, a->arr, a->max_size);
	bubble_sort(arr, a->max_size);
	*pivot1 = arr[a->max_size / 3];
	*pivot2 = arr[(a->max_size / 3) * 2];
	free(arr);
}

void	partitioning(t_deque *a, t_deque *b)
{
	int	peek;
	int	count;
	int	pivot1;
	int	pivot2;

	get_pivot(a, &pivot1, &pivot2);
	count = 0;
	while (count < a->max_size)
	{
		peek = a->peek_back(a);
		if (peek < pivot2 && peek >= pivot1)
			pb(a, b);
		else if (peek < pivot1)
		{
			pb(a, b);
			rb(b);
		}
		else
			ra(a);
		count++;
	}
	while (!a->deque_empty(a))
		pb(a, b);
}
