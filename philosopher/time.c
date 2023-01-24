/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:35:14 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/24 16:38:02 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosopher.h"

void	msleep(int time)
{
	usleep(time * 1000);
}

double	get_millisecond(struct timeval time)
{
	double	milli_second;

	milli_second = (time.tv_sec + (time.tv_usec / 1000000.0)) * 1000;
	return (milli_second);
}

