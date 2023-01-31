/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_check_status.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:40:37 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/31 14:40:38 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philosopher_starvation(t_philo_identity *_this,
			bool left_fork_use, bool right_fork_use)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1)
		% _this->shared->opt->number_of_philosophers;

	pthread_mutex_lock(&_this->shared->m_died);
	if (_this->shared->who_died == false)
	{
		pthread_mutex_unlock(&_this->shared->m_died);
		return (false);
	}
	if (left_fork_use == true)
		pthread_mutex_unlock(&_this->shared->m_fork[left]);
	if (right_fork_use == true)
		pthread_mutex_unlock(&_this->shared->m_fork[right]);
	pthread_mutex_unlock(&_this->shared->m_died);
	return (true);
}

bool	solo_philosopher(t_philo_identity *_this)
{
	if (_this->shared->opt->number_of_philosophers != 1)
		return (false);
	pthread_mutex_lock(&_this->shared->m_fork[_this->seq]);
	print_log(_this, "has taken a fork");
	msleep(_this->shared->opt->time_to_die);
	pthread_mutex_unlock(&_this->shared->m_fork[_this->seq]);
	return (true);
}
