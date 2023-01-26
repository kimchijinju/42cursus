/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_do.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:41:55 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/26 16:31:56 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>

bool	philosopher_starvation(t_philo_identity *_this, bool left_fork_use, bool right_fork_use)
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

bool	take_up_fork(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1)
		% _this->shared->opt->number_of_philosophers;

	if (philosopher_starvation(_this, false, false) == true)
		return (false);
	pthread_mutex_lock(&_this->shared->m_fork[left]);
	print_log(_this, "has taken a fork");
	if (philosopher_starvation(_this, true, false) == true)
		return (false);
	pthread_mutex_lock(&_this->shared->m_fork[right]);
	if (philosopher_starvation(_this, true, true) == true)
		return (false);
	print_log(_this, "has taken a fork");
	return (true);
}

bool	eat_spaghetti(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1)
		% _this->shared->opt->number_of_philosophers;

	if (philosopher_starvation(_this, true, true) == true)
		return (false);
	_this->shared->last_eat_time[_this->seq] = get_millisecond();
	print_log(_this, "is eating");
	msleep(_this->shared->opt->time_to_eat);
	pthread_mutex_unlock(&_this->shared->m_fork[left]);
	pthread_mutex_unlock(&_this->shared->m_fork[right]);
	if (philosopher_starvation(_this, false, false) == true)
		return (false);
	print_log(_this, "is sleeping");
	msleep(_this->shared->opt->time_to_sleep);
	if (philosopher_starvation(_this, false, false) == true)
		return (false);
	return (true);
}

bool	think(t_philo_identity *_this)
{
	print_log(_this, "is thinking");
	return (true);
}

void	*philosopher_life_cycle(void *arg)
{
	t_philo_identity	*_this;

	_this = (t_philo_identity *)arg;
	while (1)
	{
		if (take_up_fork(_this) == false)
			break ;
		if (eat_spaghetti(_this) == false)
			break ;
		if (think(_this) == false)
			break ;
	}
	return (NULL);
}
