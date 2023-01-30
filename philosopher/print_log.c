/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:09:15 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/30 17:09:29 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosopher.h"

void	print_log(t_philo_identity *_this, char *log)
{
	const long	log_time = get_millisecond() - _this->start_time;

	printf("%ld %d %s\n", log_time, _this->seq + 1, log);
}
