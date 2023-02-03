/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_is_died.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:27:55 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/31 21:09:08 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	died_flag_on(t_shared_variable *shared)
{
	pthread_mutex_lock(&shared->m_died);
	shared->who_died = true;
	pthread_mutex_unlock(&shared->m_died);
}

static long	get_last_eat_time(t_philo_identity philosopher)
{
	long	ret;

	pthread_mutex_lock(&philosopher.shared->m_last_eat_time);
	ret = get_millisecond() - philosopher.last_eat_time;
	pthread_mutex_unlock(&philosopher.shared->m_last_eat_time);
	return (ret);
}

static bool	philosopher_eat_done(t_philo_identity philosopher)
{
	bool	ret;

	pthread_mutex_lock(&philosopher.shared->m_philo_must_eat);
	ret = philosopher.eat_done;
	pthread_mutex_unlock(&philosopher.shared->m_philo_must_eat);
	return (ret);
}

bool	who_is_died(t_philo_identity *philosophers)
{
	const double	deadline = philosophers->shared->opt->time_to_die;
	double			last_eat_time;
	int				i;

	i = 0;
	while (i < philosophers->shared->opt->number_of_philosophers)
	{
		last_eat_time = get_last_eat_time(philosophers[i]);
		if (philosopher_eat_done(philosophers[i]) == true)
		{
			++i;
			continue ;
		}
		if (last_eat_time > deadline)
		{
			died_flag_on(philosophers->shared);
			print_log(&philosophers[i], "died");
			return (true);
		}
		++i;
	}
	return (false);
}
