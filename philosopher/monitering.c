/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:01:42 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/30 17:27:52 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "philosopher.h"

static void	died_flag_on(t_shared_variable *shared)
{
	pthread_mutex_lock(&shared->m_died);
	shared->who_died = true;
	pthread_mutex_unlock(&shared->m_died);
}

static long	get_last_eat_time(t_shared_variable *shared, int i)
{
	long	ret;

	pthread_mutex_lock(&shared->m_last_eat_time);
	ret = get_millisecond() - shared->last_eat_time[i];
	pthread_mutex_unlock(&shared->m_last_eat_time);
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

static bool	who_is_died(t_philo_identity *philosophers)
{
	const double	deadline = philosophers->shared->opt->time_to_die;
	double			last_eat_time;
	int				i;

	i = 0;
	while (i < philosophers->shared->opt->number_of_philosophers)
	{
		last_eat_time = get_last_eat_time(philosophers->shared, i);
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

static bool	philosophers_eat_done(t_philo_identity *philosophers)
{
	const int	number_of_philosophers = philosophers->shared
		->opt->number_of_philosophers;
	int			i;

	i = 0;
	pthread_mutex_lock(&philosophers->shared->m_philo_must_eat);
	while (i < number_of_philosophers)
	{
		if (philosophers[i].eat_done == false)
		{
			pthread_mutex_unlock(&philosophers->shared->m_philo_must_eat);
			return (false);
		}
		++i;
	}
	pthread_mutex_unlock(&philosophers->shared->m_philo_must_eat);
	return (true);
}

void	monitering_philosophers(
		t_philo_identity *philosophers)
{
	const int	number_of_philosophers = philosophers->shared->opt
		->number_of_philosophers;

	while (1)
	{
		if (who_is_died(philosophers) == true)
			break ;
		if (philosophers_eat_done(philosophers) == true)
			break ;
		usleep(100);
	}
}

void	wait_thread(t_shared_variable *shared, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < shared->opt->number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		++i;
	}
}
