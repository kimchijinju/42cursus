/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:08:50 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 09:02:30 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bubble_sort(int *arr, int size)
{
	int		i;
	int		temp;
	t_bool	swaped;

	swaped = TRUE;
	while (swaped)
	{
		i = 0;
		swaped = FALSE;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swaped = TRUE;
			}
			i++;
		}
	}
}
