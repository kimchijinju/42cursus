/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:09:15 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/31 14:44:59 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "philosopher.h"

void	msleep(int time)
{
	const long	start_time = get_millisecond();
	long		cur_time;

	cur_time = get_millisecond();
	while (cur_time - start_time < time)
		cur_time = get_millisecond();
}

long	get_millisecond(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_log(t_philo_identity *_this, char *log)
{
	const long	log_time = get_millisecond() - _this->start_time;

	printf("%ld %d %s\n", log_time, _this->seq + 1, log);
}

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
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += (*str - '0');
		str++;
	}
	return (number * sign);
}
