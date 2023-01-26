/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:35:14 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/26 14:56:03 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philosopher.h"

void	msleep(double time)
{
	const double	start_time = get_millisecond();
	double	cur_time;

	cur_time = get_millisecond();
	while (cur_time - start_time < time)
		cur_time = get_millisecond();
}

double	get_millisecond()
{
	double			milli_second;
	struct timeval	time;

	gettimeofday(&time, NULL);
	milli_second = (time.tv_sec + (time.tv_usec / 1000000.0)) * 1000.0;
	return (milli_second);
}
