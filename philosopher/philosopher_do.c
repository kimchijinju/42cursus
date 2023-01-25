/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_do.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:41:55 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/25 20:52:41 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	philosopher_starvation(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1)
		% _this->shared->opt->number_of_philosophers;

	pthread_mutex_lock(_this->shared->m_died);
	if (_this->who_died == false)
	{
		pthread_mutex_unlock(_this->shared->m_died);
		return (false);
	}
	if (_this->seq % 2 == 0)
	{
		pthread_mutex_unlock(&_this->shared->m_fork[left]);
		pthread_mutex_unlock(&_this->shared->m_fork[right]);
	}
	else
	{
		pthread_mutex_unlock(&_this->shared->m_fork[right]);
		pthread_mutex_unlock(&_this->shared->m_fork[left]);
	}
	pthread_mutex_unlock(_this->shared->m_died);
	return (true);
}
//
//static bool	_takeup(t_philo_identity *_this, int fork1, int fork2)
//{
//	
//}

bool	take_up_fork(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1)
		% _this->shared->opt->number_of_philosophers;

	if (_this->seq % 2 == 0)
	{
		pthread_mutex_lock(&_this->shared->m_fork[left]);
		if (philosopher_starvation(_this) == true)
			return (false);
		print_log(_this, "has taken a fork");
		pthread_mutex_lock(&_this->shared->m_fork[right]);
		if (philosopher_starvation(_this) == true)
			return (false);
		print_log(_this, "has taken a fork");
		return (true);
	}
	else
	{
		pthread_mutex_lock(&_this->shared->m_fork[right]);
		if (philosopher_starvation(_this) == true)
			return (false);
		print_log(_this, "has taken a fork");
		pthread_mutex_lock(&_this->shared->m_fork[left]);
		if (philosopher_starvation(_this) == true)
			return (false);
		print_log(_this, "has taken a fork");
		return (true);
	}
	return (true);
}

bool	eat_spaghetti(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1)
		% _this->shared->opt->number_of_philosophers;

	print_log(_this, "is eating");
	gettimeofday(&_this->shared->last_eat_time[_this->seq], NULL);
	msleep(_this->shared->opt->time_to_eat);
	if (philosopher_starvation(_this) == true)
		return (false);
	if (_this->seq % 2 == 0)
	{
		pthread_mutex_unlock(&_this->shared->m_fork[left]);
		pthread_mutex_unlock(&_this->shared->m_fork[right]);
	}
	else
	{
		pthread_mutex_unlock(&_this->shared->m_fork[right]);
		pthread_mutex_unlock(&_this->shared->m_fork[left]);
	}
	print_log(_this, "is sleeping");
	msleep(_this->shared->opt->time_to_sleep);
	return (true);
}

bool	think(t_philo_identity *_this)
{
	if (philosopher_starvation(_this) == true)
		return (false);
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
