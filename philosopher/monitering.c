/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:01:42 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/26 16:36:03 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosopher.h"

static void	died_flag_on(t_shared_variable *shared)
{
	pthread_mutex_lock(&shared->m_died);
	shared->who_died = true;
	pthread_mutex_unlock(&shared->m_died);
}

static bool	who_is_died(t_philo_identity *philosophers)
{
	const double	deadline = philosophers->shared->opt->time_to_die;
	double			last_eat_time;
	int				i;

	i = 0;
	while (i < philosophers->shared->opt->number_of_philosophers)
	{
		last_eat_time = get_millisecond()
			- philosophers->shared->last_eat_time[i];
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

void	monitering_philosophers(
		t_philo_identity *philosophers)
{
	while (1)
	{
		if (who_is_died(philosophers) == true)
			break ;
		usleep(100);
	}
}

void	wait_and_destory(t_shared_variable *shared, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < shared->opt->number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		++i;
	}
	i = 0;
	while (i < shared->opt->number_of_philosophers)
	{
		pthread_mutex_destroy(&(shared->m_fork[i]));
		++i;
	}
	pthread_mutex_destroy(&shared->m_died);
}
