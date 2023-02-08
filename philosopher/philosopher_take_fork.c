/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_take_fork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:32:19 by hanbkim           #+#    #+#             */
/*   Updated: 2023/02/03 19:13:37 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static bool	even_take_up(t_philo_identity *_this,
			const int left, const int right)
{
	if (philosopher_starvation(_this, false, false) == true)
		return (false);
	pthread_mutex_lock(&_this->shared->m_fork[left]);
	_this->shared->fork_state[left] = HAND;
	if (philosopher_starvation(_this, true, false) == true)
		return (false);
	print_log(_this, "has taken a fork");
	if (philosopher_starvation(_this, true, false) == true)
		return (false);
	pthread_mutex_lock(&_this->shared->m_fork[right]);
	_this->shared->fork_state[right] = HAND;
	if (philosopher_starvation(_this, true, true) == true)
		return (false);
	print_log(_this, "has taken a fork");
	return (true);
}

static bool	odd_take_up(t_philo_identity *_this,
			const int left, const int right)
{
	if (philosopher_starvation(_this, false, false) == true)
		return (false);
	pthread_mutex_lock(&_this->shared->m_fork[right]);
	_this->shared->fork_state[right] = HAND;
	if (philosopher_starvation(_this, false, true) == true)
		return (false);
	print_log(_this, "has taken a fork");
	if (philosopher_starvation(_this, false, true) == true)
		return (false);
	pthread_mutex_lock(&_this->shared->m_fork[left]);
	_this->shared->fork_state[left] = HAND;
	if (philosopher_starvation(_this, true, true) == true)
		return (false);
	print_log(_this, "has taken a fork");
	return (true);
}

bool	take_up_fork(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1)
		% _this->shared->opt->number_of_philosophers;

	if (_this->seq % 2 == 0)
	{
		if (even_take_up(_this, left, right) == false)
			return (false);
	}
	else
	{
		if (odd_take_up(_this, left, right) == false)
			return (false);
	}
	return (true);
}

bool	take_down_fork(t_philo_identity *_this)
{
	const int	left = _this->seq;
	const int	right = (_this->seq + 1)
		% _this->shared->opt->number_of_philosophers;

	if (_this->seq % 2 == 0)
	{
		_this->shared->fork_state[left] = TABLE;
		pthread_mutex_unlock(&_this->shared->m_fork[left]);
		_this->shared->fork_state[right] = TABLE;
		pthread_mutex_unlock(&_this->shared->m_fork[right]);
	}
	else
	{
		_this->shared->fork_state[right] = TABLE;
		pthread_mutex_unlock(&_this->shared->m_fork[right]);
		_this->shared->fork_state[left] = TABLE;
		pthread_mutex_unlock(&_this->shared->m_fork[left]);
	}
	if (philosopher_starvation(_this, false, false) == true)
		return (false);
	return (true);
}
