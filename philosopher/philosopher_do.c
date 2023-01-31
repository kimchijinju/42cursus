/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_do.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:41:55 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/31 14:50:41 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "philosopher.h"

bool	philosopher_eat_done(t_philo_identity *_this)
{
	bool	ret;

	pthread_mutex_lock(&_this->shared->m_philo_must_eat);
	ret = _this->philo_must_eat == 0;
	_this->eat_done = _this->philo_must_eat == 0;
	pthread_mutex_unlock(&_this->shared->m_philo_must_eat);
	return (ret);
}

bool	eat_spaghetti(t_philo_identity *_this)
{
	if (philosopher_starvation(_this, true, true) == true)
		return (false);
	pthread_mutex_lock(&_this->shared->m_last_eat_time);
	_this->shared->last_eat_time[_this->seq] = get_millisecond();
	pthread_mutex_unlock(&_this->shared->m_last_eat_time);
	print_log(_this, "is eating");
	msleep(_this->shared->opt->time_to_eat);
	pthread_mutex_lock(&_this->shared->m_philo_must_eat);
	if (_this->philo_must_eat != -1)
		--_this->philo_must_eat;
	pthread_mutex_unlock(&_this->shared->m_philo_must_eat);
	return (true);
}

bool	sleep_think(t_philo_identity *_this)
{
	print_log(_this, "is sleeping");
	msleep(_this->shared->opt->time_to_sleep);
	if (philosopher_starvation(_this, false, false) == true)
		return (false);
	print_log(_this, "is thinking");
	usleep(100);
	return (true);
}

void	*philosopher_life_cycle(void *arg)
{
	t_philo_identity	*_this;

	_this = (t_philo_identity *)arg;
	if (philosopher_eat_done(_this) == true)
		return (NULL);
	if (solo_philosopher(_this) == true)
		return (NULL);
	while (1)
	{
		if (take_up_fork(_this) == false)
			break ;
		if (eat_spaghetti(_this) == false)
			break ;
		if (take_down_fork(_this) == false)
			break ;
		if (philosopher_eat_done(_this) == true)
			break ;
		if (sleep_think(_this) == false)
			break ;
	}
	return (NULL);
}
