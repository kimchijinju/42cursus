/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:35:14 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/24 18:01:20 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philosopher.h"

void	msleep(int time) // 자야하는시간
{
	struct timeval	start_time;
	struct timeval	cur_time;

	gettimeofday(&start_time, NULL);
	while (get_millisecond(cur_time) - get_millisecond(start_time) < time)
		gettimeofday(&cur_time, NULL);
}

double	get_millisecond(struct timeval time)
{
//	double	milli_second;
	long long	milli_second;

//	milli_second = (time.tv_sec + (time.tv_usec / 1000000.0)) * 1000.0;
//	milli_second = (time.tv_sec + (time.tv_usec / 1000000.0)) * 1000.0;
	milli_second = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (milli_second);
}

