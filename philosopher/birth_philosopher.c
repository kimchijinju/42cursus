/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:06:03 by hanbkim           #+#    #+#             */
/*   Updated: 2023/01/31 21:27:01 by hanbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>

static void	shared_variable_init(t_option *opt,
			t_philo_identity **p, pthread_t **t)
{
	*p = malloc(sizeof(t_philo_identity)
			* opt->number_of_philosophers);
	*t = malloc(sizeof(pthread_t) * opt->number_of_philosophers);
	(*p)->shared = malloc(sizeof(t_shared_variable));
	(*p)->shared->m_fork = malloc(sizeof(pthread_mutex_t)
			* opt->number_of_philosophers);
	(*p)->shared->fork_state = malloc(sizeof(bool)
			* opt->number_of_philosophers);
	(*p)->shared->opt = opt;
	(*p)->shared->who_died = false;
}

static void	mutex_init(t_shared_variable *shared)
{
	int	i;

	i = 0;
	while (i < shared->opt->number_of_philosophers)
	{
		pthread_mutex_init(&(shared->m_fork[i]), NULL);
		shared->fork_state[i] = TABLE;
		++i;
	}
	pthread_mutex_init(&shared->m_died, NULL);
	pthread_mutex_init(&shared->m_last_eat_time, NULL);
	pthread_mutex_init(&shared->m_philo_must_eat, NULL);
}

static void	identity_init(t_philo_identity *philosophers)
{
	const t_option	*opt = philosophers->shared->opt;
	int				i;

	i = 0;
	while (i < opt->number_of_philosophers)
	{
		philosophers[i].shared = philosophers->shared;
		philosophers[i].seq = i;
		philosophers[i].start_time = get_millisecond();
		philosophers[i].last_eat_time = get_millisecond();
		philosophers[i].philo_must_eat = philosophers->shared->opt
			->number_of_times_each_philosopher_must_eat;
		philosophers[i].eat_done = false;
		++i;
	}
}

bool	birth_philosopher(t_option *opt,
		t_philo_identity **philosophers, pthread_t **thread)
{
	int	i;

	shared_variable_init(opt, philosophers, thread);
	mutex_init((*philosophers)->shared);
	identity_init(*philosophers);
	i = 0;
	while (i < opt->number_of_philosophers)
	{
		pthread_create(&(*thread)[i], NULL,
			philosopher_life_cycle, &(*philosophers)[i]);
		++i;
	}
	return (true);
}
