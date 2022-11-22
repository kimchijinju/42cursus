/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:35:58 by hanbkim           #+#    #+#             */
/*   Updated: 2022/10/21 13:32:53 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_alpha(char c)
{
	return ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int	ft_atoi_hexa(const char *str)
{
	int	sign;
	int	number;

	sign = 1;
	str += 2;
	number = 0;
	while ((*str >= '0' && *str <= '9') || is_alpha(*str))
	{
		number *= 16;
		if (is_alpha(*str))
			number += (ft_toupper(*str) - 'A' + 10);
		else
			number += (*str - '0');
		str++;
	}
	return (number * sign);
}
