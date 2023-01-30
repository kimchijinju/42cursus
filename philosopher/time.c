/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:35:14 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/30 17:04:20 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philosopher.h"

void	msleep(double time)
{
	const double	start_time = get_millisecond();
	double			cur_time;

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
