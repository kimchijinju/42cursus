/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:01:42 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/25 19:53:33 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	died_flag_on(t_philo_identity *philosophers)
{
	const int	number_of_philosophers = philosophers->shared
		->opt->number_of_philosophers;
	int			i;

	i = 0;
	pthread_mutex_lock(philosophers->shared->m_died);
	while (i < number_of_philosophers)
	{
		philosophers[i].who_died = true;
		++i;
	}
	pthread_mutex_unlock(philosophers->shared->m_died);
}

static bool	who_is_died(t_philo_identity *philosophers)
{
	const double	deadline = philosophers->shared->opt->time_to_die;
	double			last_eat_time;
	struct timeval	cur_time;
	int				i;

	i = 0;
	while (i < philosophers->shared->opt->number_of_philosophers)
	{
		gettimeofday(&cur_time, NULL);
		last_eat_time = get_millisecond(cur_time)
			- get_millisecond(philosophers->shared->last_eat_time[i]);
		if (last_eat_time > deadline)
		{
			died_flag_on(philosophers);
			print_log(&philosophers[i], "died");
			return (true);
		}
		++i;
	}
	return (false);
}

void	monitering_philosophers(
		t_philo_identity *philosophers)
{
	while (1)
	{
		if (who_is_died(philosophers) == true)
			break ;
	}
}

void	wait_and_destory(t_philo_identity *philosophers, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < philosophers->shared->opt->number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		++i;
	}
	i = 0;
	while (i < philosophers->shared->opt->number_of_philosophers)
	{
		pthread_mutex_destroy(&(philosophers->shared->m_fork[i]));
		++i;
	}
	pthread_mutex_destroy(philosophers->shared->m_died);
}
