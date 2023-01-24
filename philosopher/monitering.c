/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:01:42 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/24 20:20:07 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	died_flag_on(t_philo_identity *philosophers, int number_of_philosophers)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philosophers->m_died);
	while (i < number_of_philosophers)
	{
		philosophers[i].who_died = true;
		++i;
	}
	pthread_mutex_unlock(philosophers->m_died);
}

void	monitering_philosophers(
		t_philo_identity *philosophers)
{
	const double	deadline = philosophers->opt->time_to_die;
	double			last_eat_time;
	struct timeval	cur_time;
	bool			die;
	int				i;

	while (1)
	{
		i = 0;
		die = false;
		while (i < philosophers->opt->number_of_philosophers)
		{
			gettimeofday(&cur_time, NULL);
			last_eat_time = get_millisecond(cur_time) - get_millisecond(philosophers[i].last_eat_time[i]);
			if (last_eat_time > deadline)
			{
				died_flag_on(philosophers, philosophers->opt->number_of_philosophers);
				print_log(&philosophers[i], "died");
				die = true;
				break ;
			}
			++i;
		}
		if (die == true)
			return ;
	}
}

void	wait_and_destory(t_philo_identity *philosophers, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < philosophers->opt->number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		++i;
	}
	i = 0;
	while (i < philosophers->opt->number_of_philosophers)
	{
		pthread_mutex_destroy(&(philosophers->m_fork[i]));
		++i;
	}
	pthread_mutex_destroy(philosophers->m_died);
}
