/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:35:58 by hanbkim           #+#    #+#             */
/*   Updated: 2022/07/25 21:17:49 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	return (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	number;

	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	number = 0;
	//long long 처리
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += (*str - '0');
		str++;
	}
	return (number * sign);
}
