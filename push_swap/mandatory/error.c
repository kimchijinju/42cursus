/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:27:30 by hanbkim           #+#    #+#             */
/*   Updated: 2022/09/20 11:15:44 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	input_sorted(t_deque *a)
{
	int	i;

	i = 0;
	while (i < a->cur_size - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_incorrect_string(char *str)
{
	size_t	i;
	t_bool	sign;

	i = 0;
	sign = (str[i] == '-' || str[i] == '+');
	if (sign)
		str++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (TRUE);
		i++;
	}
	return (i == 0);
}

t_bool	integer_range_out(char *str)
{
	long long	number;
	int			sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += (*str - '0');
		str++;
	}
	number *= sign;
	if (number > 2147483647 || number < -2147483648)
		return (TRUE);
	return (FALSE);
}

t_bool	wrong_input(char *str)
{
	if (is_incorrect_string(str))
	{
		return (TRUE);
	}
	if (integer_range_out(str))
	{
		return (TRUE);
	}
	return (FALSE);
}

t_bool	duplicate_input(int *arr, size_t arr_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (arr[i] == arr[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}
