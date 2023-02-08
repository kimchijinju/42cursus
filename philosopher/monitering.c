/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:01:42 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/31 21:07:19 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "philosopher.h"

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
